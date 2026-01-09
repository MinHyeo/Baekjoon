#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char field[12][6];
int bomb = 0;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

bool Searching() {
	bool is_visited[12][6] = { false, };
	bool is_exploded = false;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (field[i][j] != '.' && !is_visited[i][j]) {
				vector<pair<int, int>> group;
				queue<pair<int, int>> q;
				q.push({ i, j });
				is_visited[i][j] = true;

				while (!q.empty()) {
					pair<int, int> p = q.front(); q.pop();
					group.push_back({ p.first, p.second });

					for (int k = 0; k < 4; k++) {
						int next_x = p.second + dx[k];
						int next_y = p.first + dy[k];

						if (next_x < 0 || next_x >= 6 || next_y < 0 || next_y >= 12)
							continue;
						if (is_visited[next_y][next_x]) 
							continue;
						if (field[next_y][next_x] != field[i][j]) 
							continue;
						
						is_visited[next_y][next_x] = true;
						q.push({ next_y, next_x });
					}
				}

				if (group.size() >= 4) {
					for (pair<int, int> p : group) {
						field[p.first][p.second] = '.';
					}
					is_exploded = true;
				}
			}
		}
	}

	return is_exploded;
}

void ApplyGravity() {
	for (int i = 0; i < 6; i++) {
		queue<char> q;

		for (int j = 11; j >= 0; j--) {
			if (field[j][i] != '.') {
				q.push(field[j][i]);
				field[j][i] = '.';
			}
		}
		
		int j = 11;
		while (!q.empty()) {
			field[j][i] = q.front();
			q.pop();
			j--;
		}
	}
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> field[i][j];
		}
	}

	while(true){
		if (!Searching())
			break;
		bomb += 1;
		ApplyGravity();
	}
	
	cout << bomb << "\n";

	return 0;
}