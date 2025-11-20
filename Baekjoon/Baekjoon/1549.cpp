#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> num(n + 1);
	vector<long long> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		dp[i] = dp[i - 1] + num[i];
	}

	int min_k = 0;
	long long min_cha = 1e9;
	for (int k = 1; k <= n / 2; k++) {
		for (int i = k; i <= n - k; i++) {
			long long sum_i = dp[i] - dp[i - k];

			for (int j = i + k; j <= n; j++) {
				long long sum_j = dp[j] - dp[j - k];

				long long cha = abs(sum_i - sum_j);
				if (cha < min_cha) {
					min_cha = cha;
					min_k = k;
				}
				else if (cha == min_cha) {
					min_k = k;
				}
			}
		}
	}

	cout << min_k << "\n";
	cout << min_cha << "\n";

	return 0;
}