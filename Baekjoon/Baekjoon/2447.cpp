#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<char>> board;

void DrawStar(int n, int x, int y) {
	int size = n / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;

			if (size <= 1) {
				board[x + i][y + j] = '*';
			}
			else {
				DrawStar(size, x + size * i, y + size * j);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	board = vector<vector<char>>(n, vector<char>(n, ' '));
	DrawStar(n, 0, 0);

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}

	return 0;
}