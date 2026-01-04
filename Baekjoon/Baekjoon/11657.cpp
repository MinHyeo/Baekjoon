#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Bus {
	int from;
	int to;
	int time;
};

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<Bus> buses;
	for (int i = 0; i < m; i++) {
		int from, to, time;
		cin >> from >> to >> time;

		buses.push_back({ from, to, time });
	}

	// 벨만-포드 알고리즘
	bool is_cycle = false;
	vector<long long> dist(n + 1, 1e18);
	dist[1] = 0;
	for (int i = 0; i < n; i++) {
		for (Bus bus : buses) {
			if (dist[bus.from] != 1e18 && dist[bus.to] > dist[bus.from] + bus.time) {
				dist[bus.to] = dist[bus.from] + bus.time;
				if (i == n - 1) {
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] == 1e18)
			cout << -1 << "\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}