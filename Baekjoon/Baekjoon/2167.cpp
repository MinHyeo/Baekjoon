#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> hap(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			hap[i][j] = map[i][j] + hap[i - 1][j] + hap[i][j - 1] - hap[i - 1][j - 1];
		}
	}

	int k;
	cin >> k;

	for (int index = 0; index < k; index++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;

		cout << hap[x][y] - hap[i - 1][y] - hap[x][j - 1] + hap[i - 1][j - 1] << "\n";
	}


	return 0;
}