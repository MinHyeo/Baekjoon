#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> card(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 10000));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i <= j)
				dp[i][j] = min(dp[i - 1][j], dp[i][j - i] + card[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][n] << "\n";

	return 0;
}