#include <iostream>
#include <vector>
using namespace std;

int one_count = 0, zero_count = 0, minus_count = 0;
vector<vector<int>> paper;

bool Check(int x, int y, int size) {
	int before_number = paper[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (before_number != paper[i][j]) {
				return false;
			}
		}
	}

	return true;
}

void Divide(int x, int y, int size) {
	if (Check(x, y, size)) {
		if (paper[x][y] == -1)
			minus_count++;
		else if (paper[x][y] == 0)
			zero_count++;
		else
			one_count++;
		return;
	}

	int new_size = size / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int new_x = x + new_size * i;
			int new_y = y + new_size * j;
			Divide(new_x, new_y, new_size);
		}
	}
}

int main() {
	int n;
	cin >> n;

	paper = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	Divide(0, 0, n);
	cout << minus_count << "\n";
	cout << zero_count << "\n";
	cout << one_count << "\n";

	return 0;
}