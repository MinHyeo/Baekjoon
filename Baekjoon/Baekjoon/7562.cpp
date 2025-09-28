#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Night {
	int x, y;
	int count;
};

int main() {
	int t;
	cin >> t;

	int dx[8] = { 1, -1, 2, 2, 1, -1, -2, -2 };
	int dy[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };

	while (t--) {
		int l;
		cin >> l;
		vector<vector<int>> chess(l, vector<int>(l, 0));

		int startY, startX;
		cin >> startY >> startX;
		chess[startY][startX] = 1;
		
		int endY, endX;
		cin >> endY >> endX;

		queue<Night> q;
		q.push(Night{startX, startY, 0});

		while (!q.empty()) {
			Night night = q.front();  q.pop();
			if (night.x == endX && night.y == endY) {
				cout << night.count << "\n";
				break;
			}

			for (int i = 0; i < 8; i++) {
				int nx = night.x + dx[i];
				int ny = night.y + dy[i];

				if (nx >= 0 && nx < l && ny >= 0 && ny < l) {
					if (chess[ny][nx] == 0) {
						chess[ny][nx] = 1;
						q.push(Night{ nx, ny, night.count + 1 });
					}
				}
			}
			
		}
	}

	return 0;
}