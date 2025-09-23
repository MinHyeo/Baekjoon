#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int start, end, value;
};

bool compare(Edge a, Edge b) {
	return a.value < b.value;
}

int FindParent(vector<int> parent, int a) {
	while(a != parent[a])
		a = parent[a];
	return a;
}

vector<int> UnionParent(vector<int> parent, int a, int b) {
	a = FindParent(parent, a);
	b = FindParent(parent, b);

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}

	return parent;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<Edge> computer(m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		computer[i] = { a, b, c };
	}

	sort(computer.begin(), computer.end(), compare);

	vector<int> parent(n + 1);
	for (int i = 0; i < parent.size(); i++) {
		parent[i] = i;
	}

	int result = 0;
	for (Edge edge : computer) {
		if (FindParent(parent, edge.start) != FindParent(parent, edge.end)) {
			parent = UnionParent(parent, edge.start, edge.end);
			result += edge.value;
		}
	}

	cout << result << "\n";

	return 0;
}