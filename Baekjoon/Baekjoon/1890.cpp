#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> pan(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> pan[i][j];
		}
	}

	vector<vector<long long>> dp(n, vector<long long > (n, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0)
				continue;
			if (i == n - 1 && j == n - 1)
				continue;

			if (i + pan[i][j] < n) {
				dp[i + pan[i][j]][j] += dp[i][j];
			}
			if (j + pan[i][j] < n) {
				dp[i][j + pan[i][j]] += dp[i][j];
			}
		}
	}

	cout << dp[n - 1][n - 1] << "\n";

	return 0;
}