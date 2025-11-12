#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	int root;
	vector<vector<int>> nodes(n, vector<int>());
	for (int i = 0; i < n; i++) {
		int parent;
		cin >> parent;

		// 자식 등록
		if (parent != -1)
			nodes[parent].push_back(i);
		else
			root = i;
	}

	// 삭제 노드 등록
	int del_node;
	cin >> del_node;

	// 루트가 삭제일 경우 바로 종료
	if (del_node == root) {
		cout << 0 << "\n";
		return 0;
	}

	// DFS
	stack<int> s;
	s.push(root);
	int result = 0;
	while (!s.empty()) {
		int node = s.top(); s.pop();

		bool is_leaf = true;
		for (int child : nodes[node]) {
			// 자식 노드가 삭제되면 스택에 저장X
			if (child == del_node)
				continue;
			// 자식이 존재하므로 리프가 아님
			is_leaf = false;
			s.push(child);
		}

		// 리프이면 결과 + 1
		if (is_leaf)
			result += 1;
	}

	cout << result << "\n";

	return 0;
}