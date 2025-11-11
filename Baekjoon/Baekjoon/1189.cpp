#include <iostream>
#include <vector>
using namespace std;

int r, c, k;
vector<vector<char>> map;
vector<vector<bool>> is_visited;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int result = 0;

void Backtracking(int x, int y, int depth) {
	if (depth == k) {
		if (x == c - 1 && y == 0)
			result += 1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_x >= c || next_y < 0 || next_y >= r)
			continue;
		if (is_visited[next_y][next_x] || map[next_y][next_x] == 'T')
			continue;

		is_visited[next_y][next_x] = true;
		Backtracking(next_x, next_y, depth + 1);
		is_visited[next_y][next_x] = false;
	}
}


int main() {
	cin >> r >> c >> k;

	map = vector<vector<char>>(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < c; j++) {
			map[i][j] = s[j];
		}
	}

	is_visited = vector<vector<bool>>(r, vector<bool>(c, false));
	is_visited[r - 1][0] = true;
	Backtracking(0, r - 1, 1);

	cout << result << "\n";

	return 0;
}