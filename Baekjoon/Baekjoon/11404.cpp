#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> bus(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		bus[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus[a - 1][b - 1] = min(bus[a - 1][b - 1], c);
	}

	// 플로이드-위셜 알고르즘
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				bus[j][k] = min(bus[j][k], bus[j][i] + bus[i][k]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (bus[i][j] == INF)
				cout << 0 << " ";
			else
				cout << bus[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}