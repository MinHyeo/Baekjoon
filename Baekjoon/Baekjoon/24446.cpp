#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, m, r;
	cin >> n >> m >> r;

	vector<vector<int>> edges(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(edges[i].begin(), edges[i].end(), greater<int>());
	}

	queue<pair<int, int>> q;
	vector<int> results(n + 1, -1);
	q.push({ r, 0 });
	while (!q.empty()) {
		auto v = q.front(); q.pop();

		if (results[v.first] != -1)
			continue;

		results[v.first] = v.second++;
		for (int edge : edges[v.first])
			q.push({ edge, v.second });
	}

	for (int i = 1; i <= n; i++)
		cout << results[i] << "\n";

	return 0;
}