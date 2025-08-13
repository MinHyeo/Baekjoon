#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> progression(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> progression[i];
	}

	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (progression[i] > progression[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";

	return 0;
}