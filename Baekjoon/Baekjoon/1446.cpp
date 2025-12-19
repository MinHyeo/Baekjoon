#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shortcut
{
	int start;
	int end;
	int distance;
};

bool compare(const Shortcut& a, const Shortcut& b) {
	return a.start < b.start;
}

int main() {
	int n, d;
	cin >> n >> d;

	vector<Shortcut> shortcuts;
	for (int i = 0; i < n; i++) {
		int start, end, distance;
		cin >> start >> end >> distance;

		if (start <= d && end <= d) {
			shortcuts.push_back({ start, end, distance });
		}
	}

	sort(shortcuts.begin(), shortcuts.end(), compare);
	vector<int> dp(d + 1, 10001);
	dp[0] = 0;
	for (int i = 0; i < d; i++) {
		for (Shortcut shortcut : shortcuts) {
			if (shortcut.start == i) {
				dp[shortcut.end] = min(dp[shortcut.end], dp[i] + shortcut.distance);
				//shortcuts.erase(shortcuts.begin());
			}
		}
		//cout << "distance : " << i << " : " << dp[i] + 1 << ", " << dp[i + 1] << "\n";
		dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
	}

	cout << dp[d] << "\n";

	return 0;
}