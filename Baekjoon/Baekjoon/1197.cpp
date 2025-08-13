#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int v, e;
	cin >> v >> e;
	vector<vector<int>> point(v, vector<int>(v, 0));
	vector<bool> isVisited(v, false);
	queue<pair<int, int>> q;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		point[a][b] = c;
		point[b][a] = c;
	}

	//초기화 넣기
	for (int i = 0; i < v; i++) {
		if (point[0][i] != 0) {
			pair<int, int> p;
			p.first = 0;
			p.second = i;
			q.push(p);
		}
	}
	isVisited[0] = true;

	//BFS
	while (q.empty()) {
		pair<int, int>p = q.front();
		q.pop();


	}

	return 0;
}