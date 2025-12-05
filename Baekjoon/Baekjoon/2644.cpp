#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a, b;
	cin >> a >> b;

	int m;
	cin >> m;
	vector<vector<int>> family(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		family[x][y] = 1;
		family[y][x] = 1;
	}

	queue<pair<int, int>> q;
	q.push({ a, 0 });
	vector<bool> is_visited(n + 1, false);
	bool is_search = false;

	while (!q.empty()) {
		int people = q.front().first;
		int index = q.front().second;
		q.pop();
		is_visited[people] = true;

		if (people == b) {
			cout << index << "\n";
			is_search = true;
			break;
		}	

		for (int i = 1; i < n + 1; i++) {
			if (is_visited[i] || family[people][i] == 0)
				continue;
			q.push({ i , index + 1 });
		}
	}

	if (!is_search)
		cout << -1 << "\n";

	return 0;
}