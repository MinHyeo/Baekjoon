#include <iostream>
#include <vector>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int aSize = a.length();
	int bSize = b.length();

	if (aSize > bSize) {
		string temp = a;
		a = b;
		b = temp;
		aSize = a.length();
		bSize = b.length();
	}

	vector<vector<string>> dp(aSize + 1, vector<string>(bSize + 1, ""));
	for (int i = 1; i <= aSize; i++) {
		for (int j = 1; j <= bSize; j++) {
			dp[i][j] = dp[i - 1][j].length() > dp[i][j - 1].length() ? dp[i - 1][j] : dp[i][j - 1];
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + b[j - 1];
			}
		}
	}

	cout << dp[aSize][bSize] << "\n";

	return 0;
}