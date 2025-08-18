#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> step(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> step[i];
	}

	if (n == 1) {
		cout << step[1] << "\n";
		return 0;
	}
	if (n == 2) {
		cout << step[1] + step[2] << "\n";
		return 0;
	}

	vector<int> dp(n + 1, 0);
	dp[1] = step[1];
	dp[2] = step[1] + step[2];
	dp[3] = max(step[1] + step[3], step[2] + step[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + step[i], dp[i - 3] + step[i - 1] + step[i]);
	}

	cout << dp[n] << "\n";

	return 0;
}