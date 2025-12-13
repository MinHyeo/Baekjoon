#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, s, m;
	cin >> n >> s >> m;

	vector<int> volume(n);
	for (int i = 0; i < n; i++) {
		cin >> volume[i];
	}

	vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
	dp[0][s] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i][j]) {
				if (j + volume[i] <= m)
					dp[i + 1][j + volume[i]] = true;
				if (j - volume[i] >= 0)
					dp[i + 1][j - volume[i]] = true;
			}
		}
	}

	bool is_possible = false;
	for (int i = m; i >= 0; i--) {
		if (dp[n][i]) {
			cout << i << "\n";
			is_possible = true;
			return 0;
		}
	}
	cout << "-1" << "\n";

	return 0;
}