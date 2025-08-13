#include <iostream>
using namespace std;

int main() {
	int paper[100][100] = {0};
	int p;
	cin >> p;

	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;

		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				paper[j - 1][k - 1] = 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			result += paper[i][j];
		}
	}

	cout << result << "\n";

	return 0;
}