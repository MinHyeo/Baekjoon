#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	int cheese_count = 0;
	cin >> n >> m;

	vector<vector<int>> cheese(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheese[i][j];
			if (cheese[i][j] == 1)
				cheese_count++;
		}
	}

	int time = 0, result_cheese_count = cheese_count;
	int dx[] = { 0, 1, 0 ,-1 };
	int dy[] = { -1, 0, 1, 0 };
	while (cheese_count > 0) {
		vector<vector<bool>> is_visited(n, vector<bool>(m, false));
		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		is_visited[0][0] = true;

		while (!q.empty()) {
			pair<int, int> point = q.front();  q.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = point.first + dx[i];
				int next_y = point.second + dy[i];

				if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
					continue;
				
				if (!is_visited[next_y][next_x]) {
					is_visited[next_y][next_x] = true;
					if (cheese[next_y][next_x] == 1) {
						cheese[next_y][next_x] = 0;
						cheese_count--;
					}
					else {
						q.push({ next_x, next_y });
					}
				}
			}
		}
		if (cheese_count != 0)
			result_cheese_count = cheese_count;
		time++;
	}

	cout << time << " " << result_cheese_count << "\n";

	return 0;
}