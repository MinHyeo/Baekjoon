#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> permutation(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> permutation[i];
		}

		vector<bool> is_visited(n + 1, false);
		int cycle = 0;
		for (int i = 1; i <= n; i++) {
			if (is_visited[i])
				continue;

			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int next = q.front();
				q.pop();

				if (is_visited[next]) {
					cycle++;
					break;
				}
				is_visited[next] = true;
				q.push(permutation[next]);
			}
		}

		cout << cycle << "\n";
	}

	return 0;
}