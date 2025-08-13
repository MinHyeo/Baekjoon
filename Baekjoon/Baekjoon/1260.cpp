#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void Dfs(vector<vector<int>> graph, int startPoint, int number) {
	stack<int> s;
	bool visited[1001] = { false, };

	s.push(startPoint);

	while(!s.empty()) {
		int current = s.top();
		s.pop();

		//만약 이미 방문한 노드라면 다음 노드로 넘어간다.
		if (visited[current])
			continue;

		//방문한 노드 출력
		cout << current << " ";
		visited[current] = true;

		//만약 현재 노드와 연결된 노드가 없다면 다음 노드로 넘어간다.
		if (graph[current].empty())
			continue;

		int vectorSize = graph[current].size();
		for (int j = 0; j < vectorSize; j++) {
			int max = *max_element(graph[current].begin(), graph[current].end());
			graph[current].erase(remove(graph[current].begin(), graph[current].end(), max), graph[current].end());

			if (visited[max])
				continue;

			s.push(max);
		}
	}
	cout << endl;
}

void Bfs(vector<vector<int>> graph, int startPoint, int number) {
	queue<int> q;
	bool visited[1001] = { false, };

	q.push(startPoint);

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		//만약 이미 방문한 노드라면 다음 노드로 넘어간다.
		if (visited[current])
			continue;	

		//방문한 노드 출력
		cout << current << " ";
		visited[current] = true;

		//만약 현재 노드와 연결된 노드가 없다면 다음 노드로 넘어간다.
		if (graph[current].empty())
			continue;

		int vectorSize = graph[current].size();
		for (int j = 0; j < vectorSize; j++) {
			int min = *min_element(graph[current].begin(), graph[current].end());
			graph[current].erase(remove(graph[current].begin(), graph[current].end(), min), graph[current].end());

			if (visited[min])
				continue;

			q.push(min);
		}
	}
	cout << endl;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	Dfs(graph, k, m);
	Bfs(graph, k, m);

	return 0;
}