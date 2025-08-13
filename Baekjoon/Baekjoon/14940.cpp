#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<int>> result(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				q.push({ i, j });
				result[i][j] = 0;
			}
			else if(map[i][j] == 0) {
				result[i][j] = 0;
			}
		}
	}

	int dirX[] = { 0, 1, 0 ,-1 };
	int dirY[] = { -1, 0, 1, 0 };
	int count = 0;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();

		int count = result[temp.first][temp.second] + 1;
		for (int i = 0; i < 4; i++) {
			int nx = temp.second + dirX[i];
			int ny = temp.first + dirY[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

			if (map[ny][nx] == 1 && result[ny][nx] == -1) {
				result[ny][nx] = count;
				q.push({ ny, nx });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}