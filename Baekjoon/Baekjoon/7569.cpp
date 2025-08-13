#include <iostream>
#include <queue>
using namespace std;

int m, n, h;
int box[100][100][100] = { 0 };

class Point {
public:
	int i, j, k;

	Point(int i, int j, int k) : i(i), j(j), k(k) {}
};


int main() {
	queue<Point> q;
	int m, n, h;
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int tomatoState;
				cin >> tomatoState;

				if (tomatoState == 1) {
					q.push(Point(i, j, k));
				}
				box[i][j][k] = tomatoState;
			}
		}
	}

	while (!q.empty()) {
		Point p = q.front();
		q.pop();

		// 위
		if (p.i + 1 < h && box[p.i + 1][p.j][p.k] == 0) {
			box[p.i + 1][p.j][p.k] = box[p.i][p.j][p.k] + 1;
			q.push(Point(p.i + 1, p.j, p.k));
		}
		// 아래
		if (p.i - 1 >= 0 && box[p.i - 1][p.j][p.k] == 0) {
			box[p.i - 1][p.j][p.k] = box[p.i][p.j][p.k] + 1;
			q.push(Point(p.i - 1, p.j, p.k));
		}
		// 앞
		if (p.j + 1 < n && box[p.i][p.j + 1][p.k] == 0) {
			box[p.i][p.j + 1][p.k] = box[p.i][p.j][p.k] + 1;
			q.push(Point(p.i, p.j + 1, p.k));
		}
		// 뒤
		if (p.j - 1 >= 0 && box[p.i][p.j - 1][p.k] == 0) {
			box[p.i][p.j - 1][p.k] = box[p.i][p.j][p.k] + 1;
			q.push(Point(p.i, p.j - 1, p.k));
		}
		// 오른쪽
		if (p.k + 1 < m && box[p.i][p.j][p.k + 1] == 0) {
			box[p.i][p.j][p.k + 1] = box[p.i][p.j][p.k] + 1;
			q.push(Point(p.i, p.j, p.k + 1));
		}
		// 왼쪽
		if (p.k - 1 >= 0 && box[p.i][p.j][p.k - 1] == 0) {
			box[p.i][p.j][p.k - 1] = box[p.i][p.j][p.k] + 1;
			q.push(Point(p.i, p.j, p.k - 1));
		}
	}

	int result = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				}
				result = max(result, box[i][j][k]);
			}
		}
	}
	cout << result - 1 << "\n";

	return 0;
}