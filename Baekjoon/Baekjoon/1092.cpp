#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> crane(n);
	for (int i = 0; i < n; i++) {
		cin >> crane[i];
	}

	int m;
	cin >> m;
	vector<int> box(m);
	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}

	sort(crane.rbegin(), crane.rend());
	sort(box.rbegin(), box.rend());

	if (crane[0] < box[0]) {
		cout << -1 << "\n";
		return 0;
	}
		
	vector<bool> is_visited(m, false);
	int time = 0;
	int moved = 0;
	while (moved < m) {
		time++;

		int box_index = 0;
		for (int i = 0; i < n; i++) {
			for (int j = box_index; j < m; j++) {
				if (!is_visited[j] && crane[i] >= box[j]) {
					is_visited[j] = true;
					moved += 1;
					box_index += 1;
					break;
				}
				box_index += 1;
			}
		}
	}

	cout << time << "\n";

	return 0;
}