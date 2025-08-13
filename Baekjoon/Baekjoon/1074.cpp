#include <iostream>
#include <cmath>
using namespace std;

int area[4][4] = {
	0, 1, 4, 5,
	2, 3, 6, 7,
	8, 9, 12, 13,
	10, 11, 14, 15
};

int DivideAndConquer(int N, int r, int c) {
	if (N > 2) {
		int divide = pow(2, N - 1);
		int x = r / divide;
		int y = c / divide;
		return DivideAndConquer(N - 1, r % divide, c % divide) + (x * 2 + y) * pow(4, N - 1);
	}
	else {
		return area[r][c];
	}
}

int main() {
	int N, r, c;
	cin >> N >> r >> c;

	int result = DivideAndConquer(N, r, c);
	cout << result << "\n";

	return 0;
}