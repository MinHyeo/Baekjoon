#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	vector<long long> dp(k + 1, 0);
	dp[0] = 1;
	for (int coin : coins) {
		for (int i = coin; i <= k; i++) {
			dp[i] += dp[i - coin];
		}
	}

	cout << dp[k] << "\n";

	return 0;
}