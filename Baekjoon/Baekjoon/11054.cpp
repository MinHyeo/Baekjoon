#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> increase(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				increase[i] = max(increase[i], increase[j] + 1);
			}
		}
	}

	vector<int> decrease(n, 1);
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (v[i] > v[j]) {
				decrease[i] = max(decrease[i], decrease[j] + 1);
			}
		}
	}

	int max_len = 0;
	for (int i = 0; i < n; i++) {
		max_len = max(max_len, increase[i] + decrease[i]);
	}
	cout << max_len - 1 << "\n";

	return 0;
}