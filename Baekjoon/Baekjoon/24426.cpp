#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> graph;

long long MatrixPath(int x1, int y1, int x2, int y2, int r = -1, int c = -1) {
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1e9));;

	dp[x1][y1] = graph[x1][y1];

	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (i == x1 && j == y1)
				continue;
			if (i == r && j == c)
				continue;

			long long from_up = (i > x1) ? dp[i - 1][j] : -1e9;
			long long from_left = (j > y1) ? dp[i][j - 1] : -1e9;

			dp[i][j] = graph[i][j] + max(from_up, from_left);
		}
	}

	return dp[x2][y2];
}

int main() {
	cin >> n;

	graph = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	int r, c;
	cin >> r >> c;

	long long result1 = MatrixPath(1, 1, r, c) + MatrixPath(r, c, n, n) - graph[r][c];
	long long result2 = MatrixPath(1, 1, n, n, r, c);

	cout << result1 << " " << result2 << "\n";

	return 0;
}