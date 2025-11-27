#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<bool>> is_visited;
bool is_mountain;
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int result = 0;

void GlassFire (int x, int y, int hegith) {
	is_visited[y][x] = true;

	for (int i = 0; i < 8; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
			continue;
		if (map[next_y][next_x] > hegith)
			is_mountain = false;
		if (is_visited[next_y][next_x])
			continue;

		if(map[next_y][next_x] == hegith)
			GlassFire(next_x, next_y, hegith);
	}
}

void Seraching() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!is_visited[i][j]) {
				is_mountain = true;
				GlassFire(j, i, map[i][j]);

				if (is_mountain)
					result += 1;
			}
		}
	}
}

int main() {

	cin >> n >> m;

	map = vector<vector<int>>(n, vector<int>(m));
	is_visited = vector<vector<bool>>(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	Seraching();
	cout << result << "\n";

	return 0;
}