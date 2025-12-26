#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, e;
int v1, v2;

struct Node {
	int next_node;
	int distance;
};

vector<int> Dijkstra(vector<vector<Node>> nodes, int start) {
	vector<int> distance(n, 1e9);
	distance[start] = 0;
	priority_queue<int> pq;
	pq.push(start);

	while (!pq.empty()) {
		auto node = pq.top(); pq.pop();

		for (int i = 0; i < nodes[node].size(); i++) {
			int next_node = nodes[node][i].next_node;
			int next_distance = distance[node] + nodes[node][i].distance;

			if (next_distance < distance[next_node]) {
				distance[next_node] = next_distance;
				pq.push(next_node);
			}
		}
	}

	return distance;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> e;
	vector<vector<Node>> nodes(n);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a - 1].push_back({ b - 1, c });
		nodes[b - 1].push_back({ a - 1, c });
	}
	cin >> v1 >> v2;

	vector<int> distance_0 = Dijkstra(nodes, 0);
	vector<int> distance_v1 = Dijkstra(nodes, v1 - 1);
	vector<int> distance_v2 = Dijkstra(nodes, v2 - 1);

	int case_1 = 1e9;
	if(distance_0[v1 - 1] != 1e9 && distance_v1[v2 - 1] != 1e9 && distance_v2[n - 1] != 1e9)
		case_1 = distance_0[v1 - 1] + distance_v1[v2 - 1] + distance_v2[n - 1];
	int case_2 = 1e9;
	if(distance_0[v2 - 1] != 1e9 && distance_v2[v1 - 1] != 1e9 && distance_v1[n - 1] != 1e9)
		case_2 = distance_0[v2 - 1] + distance_v2[v1 - 1] + distance_v1[n - 1];

	if (case_1 == 1e9 && case_2 == 1e9)
		cout << -1 << "\n";
	else
		cout << min(case_1, case_2) << "\n";

	return 0;
}