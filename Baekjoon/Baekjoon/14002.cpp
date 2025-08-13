#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> progression(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> progression[i];
	}

	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (progression[i] > progression[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int maxIndex = max_element(dp.begin(), dp.end()) - dp.begin();
	cout << dp[maxIndex] << "\n";

	vector<int> result;
	result.push_back(progression[maxIndex]);
	for (int i = maxIndex - 1; i >= 0; i--) {
		if (dp[i] == dp[maxIndex] - 1) {
			result.push_back(progression[i]);
			maxIndex = i;
		}
	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}