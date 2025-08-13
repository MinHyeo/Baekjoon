#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct MoveData {
	int x, y;
	bool brokenWall;
	int count;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	vector<vector<int>> map(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		string text;
		cin >> text;

		for (int j = 0; j < n; j++) {
			map[i][j] = text[j] - '0';
		}
	}

	if (n == 1 && m == 1) {
		cout << 1 << "\n";
		return 0;
	}

	queue<MoveData> q;
	q.push({ 0, 0, false, 1 });
	vector<vector<vector<bool>>> isVisited(m, vector<vector<bool>>(n, vector<bool>(2, false)));
	isVisited[0][0][0] = true;

	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };

	while(!q.empty()) {
		MoveData data = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = data.x + dx[dir];
			int ny = data.y + dy[dir];
			bool isBroken = data.brokenWall;

			if (nx == m - 1 && ny == n - 1) {
				cout << data.count + 1 << "\n";
				return 0;
			}

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
				continue;
			}

			if (map[nx][ny] == 1) {
				if (!isBroken && !isVisited[nx][ny][1]) {
					isVisited[nx][ny][1] = true;
					q.push({ nx, ny, true, data.count + 1 });
				}
					
			}
			else {
				if (!isVisited[nx][ny][isBroken]) {
					isVisited[nx][ny][isBroken] = true;
					q.push({ nx, ny, isBroken, data.count + 1 });
				}
			}
		}
	}

	cout << "-1" << "\n";

	return 0;
}