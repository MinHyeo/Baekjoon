#include <iostream>
#include <vector>
using namespace std;

int main() {
	int c, n;
	cin >> c >> n;

	vector<pair<int, int>> hongbo(n);
	for (int i = 0; i < n; i++) {
		int price, customer;
		cin >> price >> customer;
		hongbo[i] = { price, customer };
	}

	vector<int> dp(c + 100, 1e9);
	dp[0] = 0;
	for (int i = 1; i < c + 100; i++) {
		for (int j = 0; j < n; j++) {
			int price = hongbo[j].first;
			int customer = hongbo[j].second;

			if (i - customer < 0)
				continue;

			dp[i] = min(dp[i], dp[i - customer] + price);
		}
	}

	int result = 1e9;
	for (int i = c; i < c + 100; i++) {
		result = min(result, dp[i]);
	}
	cout << result << "\n";

	return 0;
}