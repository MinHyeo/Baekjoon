#include <iostream>
#include <vector>
using namespace std;

int r, c;
vector<vector<char>> garden;
vector<vector<bool>> is_visited;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int wolf_result = 0;
int ovis_result = 0;
int wolf_cur = 0;
int ovis_cur = 0;

void GrassFire(int x, int y) {
	is_visited[y][x] = true;

	if (garden[y][x] == 'v')
		wolf_cur++;
	else if (garden[y][x] == 'o')
		ovis_cur++;

	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x < 0 || next_x >= c || next_y < 0 || next_y >= r)
			continue;
		if (garden[next_y][next_x] != '#' && !is_visited[next_y][next_x])
			GrassFire(next_x, next_y);
	}
}

void Searching() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (garden[i][j] != '#' && !is_visited[i][j]) {
				ovis_cur = 0;
				wolf_cur = 0;

				GrassFire(j, i);

				if (wolf_cur >= ovis_cur)
					ovis_cur = 0;
				else
					wolf_cur = 0;

				wolf_result += wolf_cur;
				ovis_result += ovis_cur;
			}
		}
	}
}

int main() {
	cin >> r >> c;

	garden = vector<vector<char>>(r, vector<char>(c));
	is_visited = vector<vector<bool>>(r, vector<bool>(c, false));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> garden[i][j];
		}
	}

	Searching();

	cout << ovis_result << " " << wolf_result << "\n";

	return 0;
}