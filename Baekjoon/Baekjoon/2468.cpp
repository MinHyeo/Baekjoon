#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> map;
vector<vector<bool>> isChecked;

void FireGlass(int y, int x, int height) {
	if (isChecked[y][x])
		return;
	if (map[y][x] <= height) {
		isChecked[y][x] = true;
		return;
	}

	isChecked[y][x] = true;
	if (y + 1 < n) FireGlass(y + 1, x, height);
	if (x + 1 < n) FireGlass(y, x + 1, height);
	if (y - 1 >= 0) FireGlass(y - 1, x, height);
	if (x - 1 >= 0) FireGlass(y, x - 1, height);
}

int FindGround(int height) {
	isChecked = vector<vector<bool>>(n, vector<bool>(n, false));
	int count = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (isChecked[i][j] || map[i][j] <= height)
				continue;

			FireGlass(i, j, height);
			count++;
		}
	}

	return count;
}

int main() {
	cin >> n;

	int max_height = 0;
	map = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			max_height = max(map[i][j], max_height);
		}
	}

	int max_count = 0;
	for (int i = 0; i < max_height; i++) {
		max_count = max(FindGround(i), max_count);
	}

	cout << max_count << "\n";

	return 0;
}