#include <iostream>
#include <vector>
using namespace std;

int r, c, t;
vector<vector<int>> map;

int dirX[] = { 0, 1, 0, -1 };
int dirY[] = { -1, 0, 1, 0 };

pair<int, int> airClearnerTop, airClearnerBottom;

void Diffusion() {
	vector<vector<int>> temp(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] <= 0)
				continue;

			int amount = map[i][j] / 5;
			int count = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dirY[k];
				int nx = j + dirX[k];

				if (nx >= c || nx < 0 || ny >= r || ny < 0)
					continue;
				if (map[ny][nx] == -1)
					continue;

				temp[ny][nx] += amount;
				count++;
			}
			map[i][j] -= (amount * count);
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] += temp[i][j];
		}
	}
}

void AirClear() {
	//상단
	int topY = airClearnerTop.first;

	//아래
	for (int i = topY - 1; i >= 0; i--) {
		map[i + 1][0] = map[i][0];
	}
	//왼
	for (int i = 0; i < c - 1; i++) {
		map[0][i] = map[0][i + 1];
	}
	//위
	for (int i = 0; i < topY; i++) {
		map[i][c - 1] = map[i + 1][c - 1];
	}
	//오
	for (int i = c - 1; i > 1; i--) {
		map[topY][i] = map[topY][i - 1];
	}
	map[topY][1] = 0;
	map[topY][0] = -1;

	//하단
	topY = airClearnerBottom.first;
	//위
	for (int i = topY + 1; i < r - 1; i++) {
		map[i][0] = map[i + 1][0];
	}
	//왼
	for (int i = 0; i < c - 1; i++) {
		map[r - 1][i] = map[r - 1][i + 1];
	}
	//아래
	for (int i = r - 1; i > topY; i--) {
		map[i][c - 1] = map[i - 1][c - 1];
	}
	//오
	for (int i = c - 1; i > 1; i--) {
		map[topY][i] = map[topY][i - 1];
	}
	map[topY][1] = 0;
	map[topY][0] = -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> t;
	map = vector<vector<int>>(r, vector<int>(c, 0));
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];

			if (map[i][j] == -1) {
				if (airClearnerTop.first == 0) {
					airClearnerTop = { i, j };
				}
				else {
					airClearnerBottom = { i, j };
				}
			}
		}
	}

	int step = 0;
	while (t--) {
		Diffusion();
		AirClear();
	}

	int result = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if(map[i][j] > 0)
				result += map[i][j];
		}
	}
	cout << result << "\n";

	return 0;
}