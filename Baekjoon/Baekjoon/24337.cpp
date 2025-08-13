#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> building(n, 0);

    if (a + b - 1 > n) {
        cout << -1 << "\n";
        return 0;
    }
    
    int highPos;
    if (a == 1) {
        highPos = a - 1;
    }
    else {
        highPos = n - b;
    }
    
    building[highPos] = a > b ? a : b;

    for (int i = 1; i < a; i++) {
        building[highPos - i] = a - i;
    }

    for (int i = 1; i < b; i++) {
        building[n - (b - i)] = b - i;
    }

    for (int i = 0; i < n; i++) {
        if (building[i] == 0)
            cout << "1" << " ";
        else
            cout << building[i] << " ";
    }
    cout << "\n";

    return 0;
}