#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			q.push({ num, i });
			pq.push(num);
		}

		int order = 0;
		while (!q.empty()) {
			int cur_num = q.front().first;
			int cur_index = q.front().second;
			q.pop();

			if (cur_num == pq.top()) {
				pq.pop();
				order++;

				if (cur_index == m) {
					cout << order << "\n";
					break;
				}
			}
			else {
				q.push({ cur_num, cur_index });
			}
		}
	}

	return 0;
}