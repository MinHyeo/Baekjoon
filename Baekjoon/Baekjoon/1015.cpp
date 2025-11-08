#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int num, index;
		cin >> num;
		a[i] = { num, i };
	}

	sort(a.begin(), a.end());

	vector<int> result(n);
	for (int i = 0; i < n; i++) {
		result[a[i].second] = i;
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}