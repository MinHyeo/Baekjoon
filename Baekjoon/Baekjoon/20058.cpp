#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, q;
int storm_size;
vector<vector<int>> a;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void RotateSubgrid(int x, int y, int size) {
	vector<vector<int>> temp(size, vector<int>(size));

	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			temp[c][size - 1 - r] = a[y + r][x + c];
		}
	}

	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			a[y + r][x + c] = temp[r][c];
		}
	}
}

void ThawIce() {
	vector<pair<int, int>> thaw_ices;

	for (int r = 0; r < storm_size; r++) {
		for (int c = 0; c < storm_size; c++) {
			if (a[r][c] <= 0) continue;

			int count = 0;
			for (int i = 0; i < 4; i++) {
				int next_x = c + dx[i];
				int next_y = r + dy[i];

				if (next_x < 0 || next_x >= storm_size || next_y < 0 || next_y >= storm_size)
					continue;
				if (a[next_y][next_x] > 0)
					count += 1;
			}

			if (count < 3)
				thaw_ices.push_back({ r, c });
		}
	}

	for (auto ice : thaw_ices) {
		if(a[ice.first][ice.second] > 0)
			a[ice.first][ice.second] -= 1;
	}
}

void Magic(int l) {
	int subgrid_size = 1 << l;
	for (int i = 0; i < storm_size; i += subgrid_size) {
		for (int j = 0; j < storm_size; j += subgrid_size) {
			// È¸Àü
			RotateSubgrid(j, i, subgrid_size);
		}
	}
	// ³ìÀÌ±â
	ThawIce();
}

int main() {
	cin >> n >> q;
	storm_size = 1 << n;
	a = vector<vector<int>>(storm_size, vector<int>(storm_size));
	for (int i = 0; i < storm_size; i++) {
		for (int j = 0; j < storm_size; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < q; i++) {
		int l;
		cin >> l;
		Magic(l);
	}

	int hap = 0;
	for (int i = 0; i < storm_size; i++) {
		for (int j = 0; j < storm_size; j++) {
			hap += a[i][j];
		}
	}
	cout << hap << "\n";

	int max_size = 0;
	vector<vector<bool>> isVisited(storm_size, vector<bool>(storm_size, false));
	for (int i = 0; i < storm_size; i++) {
		for (int j = 0; j < storm_size; j++) {
			if (a[i][j] > 0 && !isVisited[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i, j });
				isVisited[i][j] = true;
				int current_size = 1;

				while (!q.empty()) {
					auto current = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int next_x = current.second + dx[k];
						int next_y = current.first + dy[k];
						if (next_x < 0 || next_x >= storm_size || next_y < 0 || next_y >= storm_size)
							continue;

						if (a[next_y][next_x] > 0 && !isVisited[next_y][next_x]) {
							isVisited[next_y][next_x] = true;
							q.push({ next_y, next_x });
							current_size++;
						}
					}
				}
				max_size = max(current_size, max_size);
			}
		}
	}
	cout << max_size << "\n";

	return 0;
}