#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	vector<int> dp(k + 1, 10001);
	dp[0] = 0;
	for (int i = 1; i <= k; i++) {
		for (int coin : coins) {
			if (i - coin < 0)
				continue;

			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}

	if (dp[k] == 10001)
		cout << -1 << "\n";
	else
		cout << dp[k] << "\n";

	return 0;
}