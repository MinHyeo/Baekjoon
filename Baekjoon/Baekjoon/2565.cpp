#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	
	vector<pair<int, int>> wires(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> wires[i].first >> wires[i].second;
	}
	sort(wires.begin(), wires.end());

	vector<int> dp(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (wires[i].second > wires[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << n - *max_element(dp.begin() + 1, dp.end()) << "\n";

	return 0;
}