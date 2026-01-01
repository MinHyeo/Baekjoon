#include <iostream>
#include <vector>
using namespace std;

struct Advice {
	int t;
	int p;
};

int main() {
	int n;
	cin >> n;

	vector<Advice> advices;
	for (int i = 0; i < n; i++) {
		int t, p;
		cin >> t >> p;
		advices.push_back({ t, p });
	}

	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n; i++) {
		dp[i + 1] = max(dp[i], dp[i + 1]);

		int time = i + advices[i].t;
		if (time <= n) {
			dp[time] = max(dp[time], dp[i] + advices[i].p);
		}
	}

	cout << dp[n] << "\n";

	return 0;
}