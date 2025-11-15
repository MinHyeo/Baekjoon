#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> building_time(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> building_time[i];
		}

		vector<vector<int>> build_order(n + 1, vector<int>());
		vector<int> in_degree(n + 1, 0);
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;

			build_order[x].push_back(y);
			in_degree[y] += 1;
		}

		int w;
		cin >> w;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (in_degree[i] == 0) {
				q.push(i);
			}
		}

		vector<int> build_lead_time(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			build_lead_time[i] = building_time[i];
		}
		while (!q.empty()) {
			int building = q.front(); q.pop();

			for (int next : build_order[building]) {
				build_lead_time[next] = max(build_lead_time[next], build_lead_time[building] + building_time[next]);

				if(--in_degree[next] == 0)
					q.push(next);
			}
		}

		cout << build_lead_time[w] << "\n";
	}

	return 0;
}