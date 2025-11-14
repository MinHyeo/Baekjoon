#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool numericStringLess(const std::string& a, const std::string& b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	return a <= b;
}

int main() {
	int n;
	cin >> n;

	vector<int> moneys(n);
	for (int i = 0; i < n; i++) {
		cin >> moneys[i];
	}
	int m;
	cin >> m;

	vector<string> dp(m + 1, "");
	for (int i = 1; i <= m; i++) {
		for (int j = n - 1; j >=0; j--) {
			int price = moneys[j];

			if (i - price >= 0) {
				string pre_number = dp[i - price];

				string new_number = pre_number + char('0' + j);
				if (new_number.size() > 1 && new_number[0] == '0') {
					continue;
				}

				if (numericStringLess(dp[i], new_number))
					dp[i] = new_number;
			}
		}
		if (dp[i] == "")
			dp[i] = dp[i - 1];
	}

	cout << dp[m] << "\n";

	return 0;
}