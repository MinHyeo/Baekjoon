#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> mabangjin(n, vector<int>(n, 0));

	if (n % 2 != 0) {
		int x = 0, y = n / 2;
		for (int i = 1; i <= n * n; i++) {
			mabangjin[x][y] = i;
			int nx = (x - 1 + n) % n;
			int ny = (y + 1) % n;
			if (mabangjin[nx][ny] != 0) {
				x = (x + 1) % n;
			}
			else {
				x = nx;
				y = ny;
			}
		}
	}
	else if (n % 4 == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i % 4 == j % 4) || ((i % 4 + j % 4) == 3)) {
					mabangjin[i][j] = (n * i) + j + 1;
				}
				else {
					mabangjin[i][j] = (n * n + 1) - ((n * i) + j + 1);
				}
			}
		}
	}
	else {
		int size = n / 2;
		vector<vector<int>> subMabangjin(size, vector<int>(size));

		int x = 0, y = size / 2;
		for (int i = 1; i <= size * size; i++) {
			subMabangjin[x][y] = i;
			int nx = (x - 1 + size) % size;
			int ny = (y + 1) % size;
			if (subMabangjin[nx][ny] != 0) {
				x = (x + 1) % size;
			}
			else {
				x = nx;
				y = ny;
			}
		}

		int m = n * n / 4;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				mabangjin[i][j] = subMabangjin[i][j];
				mabangjin[i + size][j + size] = subMabangjin[i][j] + m;
				mabangjin[i][j + size] = subMabangjin[i][j] + 2 * m;
				mabangjin[i + size][j] = subMabangjin[i][j] + 3 * m;
			}
		}

		int k = (n - 2) / 4;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < k; j++) {
				if (i == size / 2) continue;
				swap(mabangjin[i][j], mabangjin[i + size][j]);
			}
		}
		for (int j = 0; j < k; j++) {
			swap(mabangjin[size / 2][size / 2 + j], mabangjin[size / 2 + size][size / 2 + j]);
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < k - 1; j++) {
				swap(mabangjin[i][n - 1 - j], mabangjin[i + size][n - 1 - j]);
			}
		}
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mabangjin[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}