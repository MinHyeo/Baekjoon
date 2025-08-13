#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> map(n, vector<char>(m));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') {
				q.push({ i, j });
				map[i][j] = 'O';
			}
		}
	}

	int dirX[] = { 0, 1, 0, -1 };
	int dirY[] = { -1, 0, 1, 0 };
	int count = 0;
	while (!q.empty()) {
		pair<int, int> point = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = point.second + dirX[i];
			int ny = point.first + dirY[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;

			if (map[ny][nx] != 'X') {
				if (map[ny][nx] == 'P')
					count++;

				q.push({ ny, nx });
				map[ny][nx] = 'X';
			}
		}
	}
	if (count == 0)
		cout << "TT" << "\n";
	else
		cout << count << "\n";

	return 0;
}