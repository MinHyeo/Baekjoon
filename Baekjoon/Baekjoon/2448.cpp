#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board;

void DrawStar(int n, int x, int y) {
	if (n == 3) {
		board[y][x] = '*';
		board[y + 1][x - 1] = '*';
		board[y + 1][x + 1] = '*';
		for (int i = -2; i <= 2; i++) {
			board[y + 2][x + i] = '*';
		}
		return;
	}

	int size = n / 2;
	DrawStar(size, x, y);
	DrawStar(size, x - size, y + size);
	DrawStar(size, x + size, y + size);
}

int main() {
	int n;
	cin >> n;

	board = vector<vector<char>>(n, vector<char>(2 * n - 1, ' '));
	DrawStar(n, n - 1, 0);

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}