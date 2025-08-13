#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	bool isVisited = false;
	vector<int> edge;
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<node> nodes(n);
	queue<int> q;
	int count = 1;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		nodes[a - 1].edge.push_back(b - 1);
		nodes[b - 1].edge.push_back(a - 1);
	}

	q.push(0);
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		nodes[num].isVisited = true;

		for (int i = 0; i < nodes[num].edge.size(); i++) {
			if (!nodes[nodes[num].edge[i]].isVisited) {
				q.push(nodes[num].edge[i]);
				nodes[nodes[num].edge[i]].isVisited = true;
			}
		}

		if (q.empty()) {
			for (int i = 0; i < n; i++) {
				if (!nodes[i].isVisited) {
					q.push(i);
					count++;
					break;
				}
			}
		}
	}

	cout << count << "\n";

	return 0;
}