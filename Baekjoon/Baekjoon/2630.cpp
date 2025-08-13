#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> paper;
int white = 0, blue = 0;

void CheckedPaper(int n, int x, int y) {
	int half_n = n / 2;
	bool isCut = false;
	int checkColor = paper[x][y];

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (checkColor != paper[i][j])
				isCut = true;
		}
	}

	if (isCut) {
		CheckedPaper(half_n, x, y);
		CheckedPaper(half_n, x + half_n, y);
		CheckedPaper(half_n, x, y + half_n);
		CheckedPaper(half_n, x + half_n, y + half_n);
	}
	else {
		if (checkColor) {
			blue++;
		}
		else {
			white++;
		}
	}
}

int main() {
	int n;
	cin >> n;

	paper = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	CheckedPaper(n, 0, 0);

	cout << white << "\n" << blue << "\n";

	return 0;
}