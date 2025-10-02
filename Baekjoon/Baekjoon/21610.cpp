#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	// 물의 양 입력
	vector<vector<int>> grid(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	// 구름 저장 vector
	vector<pair<int, int>> cloud;
	cloud.push_back({ n - 1, 0 });
	cloud.push_back({ n - 1, 1 });
	cloud.push_back({ n - 2, 0 });
	cloud.push_back({ n - 2, 1 });
	// 구름 이동 방향 정의
	int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
	// 물복사버그 방향 정의
	int diag_x[4] = { -1, 1, 1, -1 };
	int diag_y[4] = { -1, -1, 1, 1 };

	// 구름 이동 명령
	for (int i = 0; i < m; i++) {
		int d, s;
		cin >> d >> s;

		// 구름 이동 및 비 내림
		vector<vector<bool>> isVisited(n, vector<bool>(n, false));
		for (auto& point : cloud) {
			int step = s % n;
			point.first = (point.first + dy[d - 1] * step + n) % n;
			point.second = (point.second + dx[d - 1] * step + n) % n;

			grid[point.first][point.second] += 1;
			isVisited[point.first][point.second] = true;
		}
		// 물복사버그 마법
		for (auto& point : cloud) {
			for (int j = 0; j < 4; j++) {
				int next_x = point.second + diag_x[j];
				int next_y = point.first + diag_y[j];

				if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
					continue;

				if (grid[next_y][next_x] > 0)
					grid[point.first][point.second] += 1;
			}
		}

		// 구름 없어짐
		cloud.clear();

		// 구름 재생성
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (grid[j][k] >= 2 && !isVisited[j][k]) {
					grid[j][k] -= 2;
					cloud.push_back({ j, k });
				}
			}
		}
	}

	// 총 물의 합 구하기
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result += grid[i][j];
		}
	}
	cout << result << "\n";

	return 0;
}