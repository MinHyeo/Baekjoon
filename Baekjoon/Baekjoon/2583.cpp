#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int m, n, k;
vector<vector<int>> board;
vector<vector<bool>> isVisited;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int BFS(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	isVisited[y][x] = true;
	int area = 1;

	while (!q.empty()) {
		auto point = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = point.first + dx[i];
			int next_y = point.second + dy[i];

			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
				continue;
			if (isVisited[next_y][next_x] || board[next_y][next_x])
				continue;

			isVisited[next_y][next_x] = true;
			q.push({ next_x, next_y });
			area++;
		}
	}
	return area;
}

int main() {
	cin >> m >> n >> k;

	board = vector<vector<int>>(m, vector<int>(n, 0));
	for (int i = 0; i < k; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				board[y][x] = 1;
			}
		}
	}

	isVisited = vector<vector<bool>>(m, vector<bool>(n, false));
	vector<int> areas;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 && !isVisited[i][j]) {
				areas.push_back(BFS(i, j));
			}
		}
	}

	sort(areas.begin(), areas.end());
	cout << areas.size() << "\n";
	for (int a : areas)
		cout << a << " ";
	cout << "\n";

	return 0;
}