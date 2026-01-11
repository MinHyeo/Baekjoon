#include <iostream>
#include <vector>
#include <stack>
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

	stack<int> s;
	vector<int> results(n + 1, 0);
	s.push(r);
	int index = 1;
	while (!s.empty()) {
		int v = s.top(); s.pop();

		if (results[v] != 0)
			continue;

		results[v] = index++;
		for (int edge : edges[v])
			s.push(edge);
	}

	for (int i = 1; i <= n; i++)
		cout << results[i] << "\n";

	return 0;
}