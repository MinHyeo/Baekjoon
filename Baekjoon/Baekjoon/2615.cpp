#include <iostream>
#include <vector>
using namespace std;

#define SIZE 19
int board[SIZE][SIZE];

int dx[] = { 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1 };

bool CheckOmok(int x, int y, int color) {
	for (int i = 0; i < 4; i++) {
		int cnt = 1;
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_x >= SIZE || next_y < 0 || next_y >= SIZE)
			continue;

		while (board[next_y][next_x] == color) {
			cnt++;
			next_x += dx[i];
			next_y += dy[i];

			if (next_x < 0 || next_x >= SIZE || next_y < 0 || next_y >= SIZE)
				break;
		}

		if (cnt == 5) {
			int back_x = x - dx[i];
			int back_y = y - dy[i];

			if (back_x >= 0 && back_x < SIZE && back_y >= 0 && back_y < SIZE && board[back_y][back_x] == color)
				continue;

			cout << color << "\n";
			cout << y + 1 << " " << x + 1 << "\n";
			return true;
		}
	}

	return false;
}

int main() {


	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] != 0) {
				if (CheckOmok(j, i, board[i][j])) {
					return 0;
				}
			}
		}
	}

	cout << 0 << "\n";

	return 0;
}