#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, 1, 0 , -1 };

class Robot {
private:
	int x, y;
	int dir;
public:
	Robot(int x, int y, int dir) : x(x), y(y), dir(dir) {}

	void Turn() {
		dir = (dir + 3) % 4;
	}

	void Move(int isFront) {
		x = x + dirX[dir] * isFront;
		y = y + dirY[dir] * isFront;
	}

	pair<int, int> GetPos() {
		pair<int, int> p(x, y);
		return p;
	}

	int GetDir() {
		return dir;
	}
};

int main() {
	int count = 1;
	int r, c, d;
	cin >> n >> m;
	cin >> r >> c >> d;

	vector<vector<int>> room(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}
	room[r][c] = -1;

	Robot robot(r, c, d);
	while (true) {
		auto pos = robot.GetPos();
		
		bool isClean = true;
		for (int i = 0; i < 4; i++) {
			int x = pos.first + dirX[i];
			int y = pos.second + dirY[i];
			if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
				continue;

			if (room[x][y] == 0) {
				isClean = false;
			}
		}

		room[pos.first][pos.second] = -1;

		if (isClean) {
			robot.Move(-1);

			pos = robot.GetPos();
			if (room[pos.first][pos.second] == 1)
				break;
		}
		else {
			robot.Turn();

			int x = pos.first + dirX[robot.GetDir()];
			int y = pos.second + dirY[robot.GetDir()];
			if (x < 0 || x > n - 1 || y < 0 || y > m - 1)
				continue;

			if (room[x][y] == 0) {
				robot.Move(1);
				pos = robot.GetPos();
				if (room[pos.first][pos.second] == 1)
					break;

				count++;
				room[x][y] = -1;
			}
		}
	}

	cout << count << "\n";

	return 0;
}