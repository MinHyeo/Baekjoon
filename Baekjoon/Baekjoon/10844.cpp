#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	long long step[101][10] = { 0 };
	for (int i = 1; i < 10; i++) {
		step[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				step[i][j] = (step[i - 1][1]) % 1000000000;
			}
			else if (j == 9) {
				step[i][j] = (step[i - 1][8]) % 1000000000;
			}
			else {
				step[i][j] = ((step[i - 1][j - 1] + step[i - 1][j + 1]) % 1000000000);
			}
		}
	}

	long long result = 0;
	for (int i = 0; i < 10; i++) {
		result = (result + step[n][i]) % 1000000000;
	}
	cout << result << "\n";

	return 0;
}