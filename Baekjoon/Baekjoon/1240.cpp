#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < n - 1; i++) {
		int a, b, d;
		cin >> a >> b >> d;

		graph[a].push_back({ b, d });
		graph[b].push_back({ a, d });
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		vector<bool> is_visited(n + 1, false);
		is_visited[a] = true;
		queue<pair<int, int>> q;
		q.push({a, 0});

		while (!q.empty()) {
			auto current = q.front();
			q.pop();

			if (current.first == b) {
				cout << current.second << "\n";
				break;
			}

			for (auto next : graph[current.first]) {
				if (is_visited[next.first])
					continue;

				is_visited[next.first] = true;
				q.push({ next.first, current.second + next.second });
			}
		}
	}

	return 0;
}