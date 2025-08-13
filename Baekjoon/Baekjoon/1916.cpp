#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Village {
	vector<pair<int, int>> cost;
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<Village> village(n);
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;

		village[s - 1].cost.push_back({ e - 1, c });
	}
	int start, end;
	cin >> start >> end;

	vector<int> cost(n, INT_MAX);
	priority_queue<pair<int, int>> pq;
	pq.push({ start - 1, 0 });
	while (!pq.empty()) {
		int v = pq.top().first;
		int c = pq.top().second;
		pq.pop();

		if (c > cost[v])
			continue;

		for (int i = 0; i < village[v].cost.size(); i++) {
			int tempCost = c + village[v].cost[i].second;
			if (tempCost < cost[village[v].cost[i].first]) {
				pq.push({ village[v].cost[i].first, tempCost });
				cost[village[v].cost[i].first] = tempCost;
			}
		}
	}

	cout << cost[end - 1] << "\n";

	return 0;
}