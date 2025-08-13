#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<pair<int, int>> home, chicken;
vector<int> aliveChicken;
int minDistance = INT16_MAX;

void Searching(int start, int depth) {
	if (depth >= m) {
		int distanceHap = 0;
		for (int i = 0; i < home.size(); i++) {
			int distance = INT16_MAX;
			for (int j = 0; j < aliveChicken.size(); j++) {
				distance = min(abs(home[i].first - chicken[aliveChicken[j]].first) + abs(home[i].second - chicken[aliveChicken[j]].second), distance);
			}
			distanceHap += distance;
		}

		minDistance = min(minDistance, distanceHap);

		return;
	}

	for (int i = start; i < chicken.size(); i++) {
		aliveChicken.push_back(i);
		Searching(i + 1, depth + 1);
		aliveChicken.pop_back();
	}
}

int main() {
	cin >> n >> m;

	map = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int data;
			cin >> data;
			map[i][j] = data;

			switch (data) {
			case 1:
				home.push_back({ i, j });
				break;
			case 2:
				chicken.push_back({ i, j });
				break;
			}
		}
	}

	Searching(0, 0);
	cout << minDistance << "\n";

	return 0;
}