#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

void backTracking(int start, int depth) {
    if (depth == M) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {
        v.push_back(i);
        backTracking(i + 1, depth + 1);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;
    backTracking(1, 0);
    return 0;
}