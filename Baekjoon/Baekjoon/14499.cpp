#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, y, x, k;
	cin >> n >> m >> y >> x >> k;
	
	vector<vector<int>> map(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	// 0 : 关搁, 1 : 困搁, 2 : 悼率, 3 : 辑率 , 4 : 巢率, 5 : 合率
	int dice[6] = { 0, };
	for (int i = 0; i < k; i++) {
		int command;
		cin >> command;

		int next_x = x + dx[command - 1];
		int next_y = y + dy[command - 1];
		if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
			continue;

		// 悼
		if (command == 1) {
			int temp = dice[2];
			dice[2] = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[1];
			dice[1] = temp;
			
		}
		// 辑
		else if (command == 2) {
			int temp = dice[2];
			dice[2] = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[0];
			dice[0] = temp;
		}
		// 合
		else if (command == 3) {
			int temp = dice[4];
			dice[4] = dice[0];
			dice[0] = dice[5];
			dice[5] = dice[1];
			dice[1] = temp;
		}
		// 巢
		else if (command == 4) {
			int temp = dice[4];
			dice[4] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[0];
			dice[0] = temp;
		}

		if (map[next_y][next_x] == 0) {
			map[next_y][next_x] = dice[0];
		}
		else {
			dice[0] = map[next_y][next_x];
			map[next_y][next_x] = 0;
		}

		cout << dice[1] << "\n";
		x = next_x;
		y = next_y;
	}

	return 0;
}