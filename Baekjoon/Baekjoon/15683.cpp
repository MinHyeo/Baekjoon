#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> room;
int cctv[6][4] = {
	{0, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 1, 0, 1},
	{1, 1, 0, 0},
	{1, 1, 0, 1},
	{1, 1, 1, 1}
};

void FindCCTV(int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
		}
	}
}

int main() {
	cin >> n >> m;
	room = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];

			if(room)
		}
	}

	FindCCTV(0, 0)

	return 0;
}