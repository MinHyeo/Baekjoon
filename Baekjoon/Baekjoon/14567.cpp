#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> subjects(n + 1, vector<int>());
	vector<int> inDegree(n + 1, 0);
	vector<int> result(n + 1, 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		subjects[a].push_back(b);
		inDegree[b] += 1;
	}

	// 위상정렬
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int subject = q.front(); q.pop();\

		for (int next : subjects[subject]) {
			if (--inDegree[next] == 0)
				q.push(next);
			result[next] = max(result[next], result[subject] + 1);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}
	cout << "\n";
	
	return 0;
}