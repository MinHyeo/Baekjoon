#include <iostream>
#include <algorithm>
using namespace std;

int number[100000];
int dp[100000];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	dp[0] = number[0];
	int maxSum = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(number[i], dp[i - 1] + number[i]);
		maxSum = max(maxSum, dp[i]);
	}

	cout << maxSum << "\n";

	return 0;
}