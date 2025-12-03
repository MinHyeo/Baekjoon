#include <iostream>
#include <vector>
using namespace std;

int main() {
	string n;
	cin >> n;

	int numbers[10] = { 0 };
	vector<int> dp(n.size() + 1, 0);

	for (int i = 1; i <= n.size(); i++) {
		int num = n[i - 1] - '0';
		if (num == 9 || num == 6) {
			num = numbers[6] > numbers[9] ? 9 : 6;
		}
		dp[i] = max(dp[i - 1], ++numbers[num]);
	}


	cout << dp[n.size()];

	return 0;
}