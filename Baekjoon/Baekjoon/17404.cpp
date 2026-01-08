#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> cost(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	int min_result = 1e9;
	for (int i = 0; i < 3; i++) {
		vector<vector<int>> dp(n, vector<int>(3, 1000));
		dp[0][i] = cost[0][i];

		for (int j = 1; j < n; j++) {
			dp[j][0] = cost[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = cost[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = cost[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		for (int j = 0; j < 3; j++) {
			if (i != j) {
				min_result = min(min_result, dp[n - 1][j]);
			}
		}
	}

	cout << min_result << "\n";

	return 0;
}