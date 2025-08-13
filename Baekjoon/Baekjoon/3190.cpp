#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

int n, k;
vector<vector<int>> map;
int dirX[] = {-1, 0, 1, 0};
int dirY[] = { 0, 1, 0 , -1 };

class Snake {
private:
	list<pair<int, int>> points;
	int dir = 1;
public:
	void Init() {
		points.push_front({ 0, 0 });
	}

	bool Move() {
		int x = points.front().first + dirX[dir];
		int y = points.front().second + dirY[dir];

		if (x < 0 || x >= n || y < 0 || y >= n)
			return true;
		for (const pair<int, int>& point : points) {
			if (point.first == x && point.second == y)
				return true;
		}

		points.push_front({ x, y });
		if (map[x][y] == 1) {
			map[x][y] = 0;
		}
		else {
			points.pop_back();
		}

		return false;
	}

	void Turn(char dir) {
		switch (dir) {
		case 'D':
			this->dir += 1;
			break;
		case 'L':
			this->dir -= 1;
			break;
		}
		this->dir = (this->dir + 4) % 4;
	}
};

int main() {
	cin >> n >> k;

	map = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;

		map[x - 1][y - 1] = 1;
	}

	int l;
	cin >> l;
	queue<pair<int, char>> commands;
	for (int i = 0; i < l; i++) {
		int timer;
		char dir;

		cin >> timer >> dir;
		commands.push({ timer, dir });
	}

	Snake snake;
	snake.Init();
	int count = 0;

	pair<int, char> command = commands.front();
	commands.pop();
	while(true) {
		count++;
		bool isEnd = snake.Move();
		if (isEnd)
			break;

		if (count == command.first) {
			snake.Turn(command.second);
			if (!commands.empty()) {
				command = commands.front();
				commands.pop();
			}
		}
	}

	cout << count << "\n";

	return 0;
}