#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> numbers(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int number;
		cin >> number;

		if (binary_search(numbers.begin(), numbers.end(), number)) {
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
	cout << "\n";

	return 0;
}