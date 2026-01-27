#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> numbers(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}

	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i] = numbers[i];
		for (int j = 1; j < i; j++) {
			if (numbers[i] > numbers[j]) {
				dp[i] = max(dp[i], dp[j] + numbers[i]);
			}
		}
	}

	cout << *max_element(dp.begin() + 1, dp.end()) << "\n";

	return 0;
}