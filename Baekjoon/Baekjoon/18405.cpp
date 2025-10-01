#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Virus {
	int num;
	int x, y;

	bool operator<(const Virus& other) const {
		return num > other.num;
	}
};

int main() {
	int n, k;
	cin >> n >> k;

	priority_queue<Virus> pq;
	vector<vector<int>> test_tube(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> test_tube[i][j];

			if (test_tube[i][j] != 0) {
				pq.push(Virus{test_tube[i][j], j, i});
			}
		}
	}

	int s, x, y;
	cin >> s >> x >> y;

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	for (int i = 0; i < s; i++) {
		priority_queue<Virus> temp_pq;

		while (!pq.empty()) {
			Virus virus = pq.top(); pq.pop();

			for (int j = 0; j < 4; j++) {
				int next_x = virus.x + dx[j];
				int next_y = virus.y + dy[j];

				if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
					continue;

				if (test_tube[next_y][next_x] == 0) {
					test_tube[next_y][next_x] = virus.num;
					temp_pq.push(Virus{ virus.num, next_x, next_y });
				}
			}
		}
		pq = temp_pq;
	}

	cout << test_tube[x - 1][y - 1] << "\n";

	return 0;
}