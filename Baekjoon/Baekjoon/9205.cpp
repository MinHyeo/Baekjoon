#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

bool IsArrive(pair<int, int> at, pair<int, int> to) {
	int dis = abs(at.first - to.first) + abs(at.second - to.second);
	if (dis <= 1000)
		return true;
	return false;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		pair<int, int> home;
		vector<pair<int, int>> store(n);
		pair<int, int> festival;

		// 좌표 값들 입력 받음
		cin >> home.first >> home.second;
		for (int i = 0; i < n; i++) {
			cin >> store[i].first >> store[i].second;
		}
		cin >> festival.first >> festival.second;

		// 집에서 출발하는걸 queue에 저장
		queue<pair<int, int>> q;
		q.push(home);

		bool is_arrive = false;
		vector<bool> is_visited(n, false);
		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			// 페스티벌에 도착 가능한가?
			if (IsArrive(cur, festival)) {
				is_arrive = true;
				break;
			}

			// 갈 수 있는 편의점 탐색
			for (int i = 0; i < n; i++) {
				if (IsArrive(cur, store[i]) && !is_visited[i]) {
					q.push(store[i]);
					is_visited[i] = true;
				}
			}
		}

		if (is_arrive)
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}

	return 0;
}