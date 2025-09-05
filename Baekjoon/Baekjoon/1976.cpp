#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> city(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> city[i][j];
			if (i == j)
				city[i][j] = 1;
		}
	}

	vector<int> travel(m);
	for (int i = 0; i < m; i++) {
		cin >> travel[i];
	}

	stack<int> s;
	vector<bool> isVisited(n + 1, false);
	int index = 0;
	for (int i = 1; i <= n; i++) {
		if (city[travel[index]][i] == 1) {
			s.push(i);
			isVisited[i] = true;
		}
	}
	index++;

	while (!s.empty()) {
		if (index >= m) {
			cout << "YES" << "\n";
			return 0;
		}

		int travelIndex = s.top();
		s.pop();

		if (travelIndex == travel[index]) {
			isVisited.assign(isVisited.size(), false);
			for (int i = 1; i <= n; i++) {
				if (city[travelIndex][i] == 1) {
					if (isVisited[i])
						continue;
					s.push(i);
					isVisited[i] = true;
				}
			}
			index++;
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (city[travelIndex][i] == 1) {
					if (isVisited[i])
						continue;
					s.push(i);
					isVisited[i] = true;
				}
			}
		}
	}

	cout << "NO" << "\n";

	return 0;
}