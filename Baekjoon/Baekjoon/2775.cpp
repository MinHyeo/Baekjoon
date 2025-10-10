#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;

	vector<vector<int>> apt(15, vector<int>(15, 0));
	for (int i = 1; i <= 14; i++) {
		apt[0][i] = i;
	}
	for (int i = 1; i <= 14; ++i) {
		for (int j = 1; j <= 14; ++j) {
			apt[i][j] = apt[i][j - 1] + apt[i - 1][j];
		}
	}

	for (int i = 0; i < t; ++i) {
		int k, n;
		std::cin >> k >> n;
		std::cout << apt[k][n] << "\n";
	}

	return 0;
}