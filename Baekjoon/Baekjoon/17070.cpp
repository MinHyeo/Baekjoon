#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pipe {
	int y, x;
	int type;
};

int main() {
	int n;
	cin >> n;

	vector<vector<int>> map(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	map[0][0] = 2;
	map[0][1] = 2;
	queue<Pipe> q;
	q.push({ 0, 1, 0 });
	int result = 0;

	while (!q.empty()) {
		Pipe pipe = q.front();
		q.pop();

		if (pipe.x == n - 1 && pipe.y == n - 1) {
			result += 1;
			continue;
		}

		if ((pipe.type == 0 || pipe.type == 2) && !(pipe.x + 1 >= n) && map[pipe.y][pipe.x + 1] != 1) {
			q.push({ pipe.y, pipe.x + 1, 0 });
		}
		if ((pipe.type == 1 || pipe.type == 2) && !(pipe.y + 1 >= n) && map[pipe.y + 1][pipe.x] != 1) {
			q.push({ pipe.y + 1, pipe.x, 1 });
		}
		if (!(pipe.x + 1 >= n || pipe.y + 1 >= n) && map[pipe.y + 1][pipe.x + 1] != 1 && map[pipe.y + 1][pipe.x] != 1 && map[pipe.y][pipe.x + 1] != 1) {
			q.push({ pipe.y + 1, pipe.x + 1, 2 });
		}
	}

	cout << result << "\n";

	return 0;
}