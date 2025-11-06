#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	int q;
	cin >> q;

	vector<vector<int>> dp(26, vector<int>(s.length(), 0));

	dp[s[0] - 'a'][0] = 1;
	for (int i = 1; i < s.length(); i++) {
		for (int j = 0; j < 26; j++) {
			dp[j][i] = dp[j][i - 1];
		}

		dp[s[i] - 'a'][i] += 1;
	}

	for (int i = 0; i < q; i++) {
		char a;
		int index_start, index_end;
		cin >> a >> index_start >> index_end;

		int count_end = dp[a - 'a'][index_end];
		int count_start = (index_start == 0) ? 0 : dp[a - 'a'][index_start - 1];

		cout << count_end - count_start << "\n";
	}

	return 0;
}