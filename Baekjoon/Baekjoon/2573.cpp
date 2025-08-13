#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> sea;
vector<vector<bool>> isChecked;

int dirX[] = {0, 1, 0, -1};
int dirY[] = {-1, 0, 1, 0};

void GlassFire(int x, int y) {
	isChecked[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int newX = x + dirX[i];
		int newY = y + dirY[i];

		if (newX < 0 || newX >= n || newY < 0 || newY >= m)
			continue;
		if(!isChecked[newX][newY])
			GlassFire(newX, newY);
	}
}

int Timer() {
	int year = 0;

	int area;
	do {
		area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (isChecked[i][j] == false) {
					area++;
					GlassFire(i, j);
				}
			}
		}
		if (area >= 2)
			break;

		vector<vector<int>> melt(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (sea[i][j] != 0) {
					for (int l = 0; l < 4; l++) {
						int newX = i + dirX[l];
						int newY = j + dirY[l];

						if (newX < 0 || newX >= n || newY < 0 || newY >= m)
							continue;
						if (sea[newX][newY] == 0)
							melt[i][j]++;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (sea[i][j] > 0) {
					sea[i][j] -= melt[i][j];
					if (sea[i][j] < 0)
						sea[i][j] = 0;
					isChecked[i][j] = (sea[i][j] == 0);
				}
			}
		}

		year++;
	} while (area == 1);

	if (area == 0)
		year = 0;
	return year;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	sea = vector<vector<int>>(n, vector<int>(m, 0));
	isChecked = vector<vector<bool>>(n, vector<bool>(m, true));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> sea[i][j];

			if(sea[i][j] != 0)
				isChecked[i][j] = false;
		}
	}

	int year = Timer();
	cout << year << "\n";

	return 0;
}