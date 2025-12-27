#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int k;
	cin >> k;

	while (k--) {
		int v, e;
		cin >> v >> e;

		vector<vector<int>> graph(v);
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			graph[a - 1].push_back(b - 1);
			graph[b - 1].push_back(a - 1);
		}

		vector<int> colors(v, -1);
		bool is_result = true;
		for (int i = 0; i < v; i++) {
			if (colors[i] == -1) {
				stack<int> s;
				s.push(i);
				colors[i] = 0;

				while (!s.empty()) {
					int point = s.top(); s.pop();

					for (int next : graph[point]) {
						if (colors[next] == -1) {
							colors[next] = 1 - colors[point];
							s.push(next);
						}
						else if (colors[next] == colors[point]) {
							is_result = false;
							goto END;
						}
					}
				}
			}
		}

		END:
		if (is_result)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}