#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Memorie {
	int red_x, red_y;
	int blue_x, blue_y;
	int count;
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> map(n, vector<char>(m));
	Memorie start;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'R') {
				start.red_x = j;
				start.red_y = i;
				s[j] = '.';
			}
			else if (s[j] == 'B') {
				start.blue_x = j;
				start.blue_y = i;
				s[j] = '.';
			}
			map[i][j] = s[j];
		}
	}

	start.count = 0;
	queue<Memorie> q;
	q.push(start);

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	while(!q.empty()) {
		Memorie point = q.front(); q.pop();

		// 10번 넘으면 종료
		if (point.count >= 10) {
			cout << "-1" << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int next_red_x = point.red_x;
			int next_red_y = point.red_y;
			int next_blue_x = point.blue_x;
			int next_blue_y = point.blue_y;

			bool is_red_hole = false;
			bool is_blue_hole = false;

			while (true) {
				if (map[next_red_y + dy[i]][next_red_x + dx[i]] == '#')
					break;
				next_red_x += dx[i];
				next_red_y += dy[i];
				if (map[next_red_y][next_red_x] == 'O') {
					is_red_hole = true;
					break;
				}
			}

			while (true) {
				if (map[next_blue_y + dy[i]][next_blue_x + dx[i]] == '#')
					break;
				next_blue_x += dx[i];
				next_blue_y += dy[i];
				if (map[next_blue_y][next_blue_x] == 'O') {
					is_blue_hole = true;
					break;
				}
			}

			if (is_blue_hole)
				continue;

			if (is_red_hole) {
				cout << point.count + 1 << "\n";
				return 0;
			}

			if (next_red_x == next_blue_x && next_red_y == next_blue_y) {
				int red_dist = abs(next_red_x - point.red_x) + abs(next_red_y - point.red_y);
				int blue_dist = abs(next_blue_x - point.blue_x) + abs(next_blue_y - point.blue_y);

				if (red_dist > blue_dist) {
					next_red_x -= dx[i];
					next_red_y -= dy[i];
				}
				else {
					next_blue_x -= dx[i];
					next_blue_y -= dy[i];
				}
			}

			q.push({ next_red_x, next_red_y, next_blue_x, next_blue_y, point.count + 1 });
		}
	}

	cout << "-1" << "\n";

	return 0;
}