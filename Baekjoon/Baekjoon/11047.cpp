#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> money(n);
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}

	int result = 0;
	for (int i = n - 1; i >= 0; i--) {
		result += (k / money[i]);
		k %= money[i];
	}

	cout << result << "\n";
}