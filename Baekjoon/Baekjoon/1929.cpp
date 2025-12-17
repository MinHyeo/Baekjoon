#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	vector<bool> is_checked(n + 1, true);
	vector<int> results;
	for (int i = 2; i <= n; i++) {
		if (is_checked[i]) {
			if (i >= m)
				results.push_back(i);
			for (int j = i; j <= n; j += i) {
				is_checked[j] = false;
			}
		}
	}

	for (int result : results) {
		cout << result << "\n";
	}

	return 0;
}