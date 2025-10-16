#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int r, c;
vector<vector<char>> board;

int max_room = 0;
vector<bool> is_visited(26, false);

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void BackTrarking(int x, int y, int room_count) {
	max_room = max(max_room, room_count);

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_x >= c || next_y < 0 || next_y >= r)
			continue;
		if (is_visited[board[next_y][next_x] - 'A'])
			continue;

		is_visited[board[next_y][next_x] - 'A'] = true;
		BackTrarking(next_x, next_y, room_count + 1);
		is_visited[board[next_y][next_x] - 'A'] = false;
	}
}

int main() {
	cin >> r >> c;

	board = vector<vector<char>>(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			board[i][j] = s[j];
		}
	}

	is_visited[board[0][0] - 'A'] = true;
	BackTrarking(0, 0, 1);

	cout << max_room << "\n";

	return 0;
}