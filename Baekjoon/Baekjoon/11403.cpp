#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> graph;
vector<bool> is_visited;

void Dfs(int start, int cur) {
	for (int next = 0; next < n; next++) {
		if (graph[cur][next] && !is_visited[next]) {
			is_visited[next] = true;
			Dfs(start, next);
		}
	}
}

int main() {
	cin >> n;

	graph = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		is_visited = vector<bool>(n, false);
		Dfs(i, i);

		for (int j = 0; j < n; j++) {
			cout << (is_visited[j] ? 1 : 0) << " ";
		}
		cout << "\n";
	}

	return 0;
}