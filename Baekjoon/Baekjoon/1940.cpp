#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int start = 0;
	int end = n - 1;
	int count = 0;

	while (start < end) {
		int sum = v[start] + v[end];

		if (sum == m) {
			count++;
			start++;
			end--;
		}
		else if (sum > m) {
			end--;
		}
		else {
			start++;
		}
	}

	cout << count << "\n";

	return 0;
}