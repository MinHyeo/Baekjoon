#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> v(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<int> result(n + 1, 0);
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int num = q.front();
		q.pop();

		for (int a : v[num]) {
			if (result[a] == 0) {
				result[a] = num;
				q.push(a);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}