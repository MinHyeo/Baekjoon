#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> team;
vector<bool> is_visited;
int min_stat = INT16_MAX;

void BackTrarking(int start, int depth) {
	if (depth == n / 2) {
		int start_stat = 0;
		int link_stat = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (is_visited[i] && is_visited[j])
					start_stat += team[i][j] + team[j][i];
				else if(!is_visited[i] && !is_visited[j])
					link_stat += team[i][j] + team[j][i];
			}
		}

		min_stat = min(min_stat, abs(start_stat - link_stat));
		return;
	}

	for (int i = start; i < n; i++) {
		if (!is_visited[i]) {
			is_visited[i] = true;
			BackTrarking(i + 1, depth + 1);
			is_visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	team = vector<vector<int>>(n, vector<int>(n));
	is_visited = vector<bool>(n, false);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> team[i][j];
		}
	}

	BackTrarking(0, 0);

	cout << min_stat << "\n";

	return 0;
}