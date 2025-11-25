#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> computer(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		computer[b - 1].push_back(a - 1);
	}

	int max_count = 0;
	vector<int> counts(n, 0);
	for (int i = 0; i < n; i++) {
		vector<bool> is_visited(n, false);

		queue<int> q;
		q.push(i);
		counts[i] = 1;
		is_visited[i] = true;

		while (!q.empty()) {
			int current_computer = q.front(); q.pop();

			for (int index : computer[current_computer]) {
				if (!is_visited[index]) {
					is_visited[index] = true;
					counts[i]++;
					q.push(index);
				}
			}
		}

		max_count = max(max_count, counts[i]);
	}

	for (int i = 0; i < n; i++) {
		if (counts[i] == max_count) {
			cout << i + 1 << " ";
		}
	}

	return 0;
}