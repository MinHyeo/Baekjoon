#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> picture;
int max_size = 0, count_picture = 0;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int GrassFire(int x, int y, int size) {
	picture[y][x] = 0;
	size++;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
			continue;

		if (picture[next_y][next_x])
			size = GrassFire(next_x, next_y, size);
	}

	return size;
}

void Searching() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (picture[i][j]) {
				int size = GrassFire(j, i, 0);
				count_picture++;
				max_size = max(max_size, size);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	picture = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> picture[i][j];
		}
	}

	Searching();

	cout << count_picture << "\n";
	cout << max_size << "\n";

	return 0;
}