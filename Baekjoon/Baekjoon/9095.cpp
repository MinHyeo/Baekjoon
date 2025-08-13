#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;

	vector<int> dp;
	dp.push_back(1);
	dp.push_back(2);
	dp.push_back(4);

	for (int i = 3; i <= 11; i++) {
		dp.push_back(dp[i - 3] + dp[i - 2] + dp[i - 1]);
	}

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		cout << dp[n - 1] << "\n";
	}

	return 0;
}