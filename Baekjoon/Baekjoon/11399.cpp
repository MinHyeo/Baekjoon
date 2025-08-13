#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int total = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			total += v[i];
		}
		else {
			v[i] += v[i - 1];
			total += v[i];
		}
	}
	cout << total << "\n";

	return 0;
}