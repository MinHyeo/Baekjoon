#include <iostream>
#include <vector>
using namespace std;

int main() {
	int v, e;
	cin >> v >> e;

	vector<vector<int>> graph(v + 1, vector<int>(v + 1, 1e9));
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a][b] = c;
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			for (int k = 1; k <= v; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}

	int result = 1e9;
	for (int i = 1; i <= v; i++) {
		result = min(result, graph[i][i]);
	}

	if (result != 1e9)
		cout << result << "\n";
	else
		cout << -1 << "\n";

	return 0;
}