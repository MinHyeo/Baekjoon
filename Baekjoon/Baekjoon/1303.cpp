#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, m;
vector<vector<char>> war;
int white_score = 0, blue_score = 0;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void FireGrass(char team, int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	war[y][x] = ' ';
	int count = 1;

	while (!q.empty()) {
		int new_x = q.front().first;
		int new_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = new_x + dx[i];
			int next_y = new_y + dy[i];

			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;

			if (war[next_y][next_x] == team) {
				q.push({ next_x, next_y });
				war[next_y][next_x] = ' ';
				count += 1;
			}
		}
	}

	int score = pow(count, 2);
	if (team == 'W')
		white_score += score;
	else
		blue_score += score;
}

void Searching() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (war[i][j] == 'W' || war[i][j] == 'B') {
				FireGrass(war[i][j], j, i);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	war = vector<vector<char>>(m, vector<char>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> war[i][j];
		}
	}

	Searching();

	cout << white_score << "\n";
	cout << blue_score << "\n";

	return 0;
}