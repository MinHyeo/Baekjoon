#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> line(n + 1);
	vector<int> inDegree(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		line[a].push_back(b);
		inDegree[b] += 1;
	}

	// 위상정렬
	vector<int> result;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int num = q.front(); q.pop();
		result.push_back(num);

		for (int height : line[num]) {
			if(--inDegree[height] == 0)
				q.push(height);
		}
	}

	for (int i : result) {
		cout << i << " ";
	}
	cout << "\n";

	return 0;
}