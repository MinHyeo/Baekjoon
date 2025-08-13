#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirX[4] = { -1, 0, 0, 1 };
int dirY[4] = { 0, -1, 1, 0 };

int n, sharkSize, timer, eatCount;
pair<int, int> sharkPoint;
vector<vector<int>> map;

struct Fish {
	int x, y, dist;
	bool operator<(const Fish& other) const{
		if (dist != other.dist) return dist > other.dist;
		if (x != other.x) return x > other.x;
		return y > other.y;
	}
};

bool Move() {
	queue<pair<int, int>> q;
	vector<vector<int>> dist(n, vector<int>(n, -1));
	q.push(sharkPoint);
	dist[sharkPoint.first][sharkPoint.second] = 0;
	priority_queue<Fish> canEat;

	while (!q.empty()) {
		pair<int, int> point = q.front();
		q.pop();

		if (map[point.first][point.second] <= sharkSize) {
			if (map[point.first][point.second] == sharkSize || map[point.first][point.second] == 0) {
				for (int i = 0; i < 4; i++) {
					int nx = point.first + dirX[i];
					int ny = point.second + dirY[i];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (dist[nx][ny] > -1)
						continue;

					q.push({ nx, ny });
					dist[nx][ny] = dist[point.first][point.second] + 1;
				}
			}
			else {
				canEat.push({ point.first, point.second, dist[point.first][point.second] });
			}
		}
	}

	if (canEat.empty())
		return true;

	Fish target = canEat.top();
	sharkPoint = { target.x, target.y };
	map[sharkPoint.first][sharkPoint.second] = 0;
	if (++eatCount == sharkSize) {
		sharkSize++;
		eatCount = 0;
	}
		
	timer += target.dist;

	return false;
}

void Searching() {
	bool isEnd = false;
	while (!isEnd) {
		isEnd = Move();
	}
}

int main() {
	cin >> n;
	map = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				sharkPoint = pair<int, int>(i, j);
				map[i][j] = 0;
			}
		}
	}

	sharkSize = 2;
	timer = 0;
	eatCount = 0;
	Searching();

	cout << timer << "\n";

	return 0;
}