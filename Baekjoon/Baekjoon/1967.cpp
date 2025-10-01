#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> nodes;
vector<bool> isVisited;
int maxValue = 0;
int maxIndex = 0;

void Dfs(int index, int value) {
	if (value > maxValue) {
		maxValue = value;
		maxIndex = index;
	}

	for (pair<int, int> node : nodes[index]) {
		if (isVisited[node.first])
			continue;

		isVisited[node.first] = true;
		Dfs(node.first, value + node.second);
	}
}

int main() {
	int n;
	cin >> n;

	nodes = vector<vector<pair<int, int>>>(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a - 1].push_back({ b - 1, c });
		nodes[b - 1].push_back({ a - 1, c });
	}

	isVisited = vector<bool>(n, false);
	isVisited[0] = true;
	Dfs(0, 0);

	isVisited = vector<bool>(n, false);
	isVisited[maxIndex] = true;
	Dfs(maxIndex, 0);

	cout << maxValue << "\n";

	return 0;
}