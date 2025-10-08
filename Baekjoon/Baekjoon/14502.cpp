#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int max_safe_area = 0;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int CountSafeArea(vector<vector<int>> lab) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
}

void SpreadVirus(vector<vector<int>> lab, queue<pair<int, int>> q) {
	while (!q.empty()) {
		auto point = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++) {
			int next_x = point.second + dx[i];
			int next_y = point.first + dy[i];

			if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
				continue;
			if (lab[next_y][next_x] != 0)
				continue;

			lab[next_y][next_x] = 2;
			q.push({ next_y, next_x });
		}
	}

	max_safe_area = max(CountSafeArea(lab), max_safe_area);
}

int main() {
	cin >> n >> m;

	vector<vector<int>> lab = vector<vector<int>>(n, vector<int>(m));
	vector<pair<int, int>> empty_points;
	queue<pair<int, int>> virus_points;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];

			if (lab[i][j] == 0)
				empty_points.push_back({ i, j });
			if (lab[i][j] == 2)
				virus_points.push({ i, j });
		}
	}

	int empty_point_count = empty_points.size();
	for (int i = 0; i < empty_point_count; i++) {
		for (int j = i + 1; j < empty_point_count; j++) {
			for (int k = j + 1; k < empty_point_count; k++) {
				vector<vector<int>> copy_lab = lab;

				copy_lab[empty_points[i].first][empty_points[i].second] = 1;
				copy_lab[empty_points[j].first][empty_points[j].second] = 1;
				copy_lab[empty_points[k].first][empty_points[k].second] = 1;

				SpreadVirus(copy_lab, virus_points);
			}
		}
	}

	cout << max_safe_area << "\n";

	return 0;
}