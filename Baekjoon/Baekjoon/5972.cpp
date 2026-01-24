#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	vector<int> value(n + 1, INT_MAX);
	value[1] = 0;
	queue<int> s;
	s.push(1);
	while (!s.empty()) {
		int next = s.front(); s.pop();

		for (pair<int, int> p : graph[next]) {
			if (value[p.first] > value[next] + p.second) {
				value[p.first] = value[next] + p.second;
				s.push(p.first);
			}
		}
	}

	cout << value[n] << "\n";

	return 0;
}