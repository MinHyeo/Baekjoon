#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> grid;

// 결과값
int result = 0;

// 토네이도 이동 방향 정의
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 모래 분산 비율 마스크
int sand_mask[5][5] = {
	{0, 0, 2, 0, 0},
	{0, 10, 7, 1, 0},
	{5, 0, 0, 0, 0},
	{0, 10, 7, 1, 0},
	{0, 0, 2, 0, 0}
};

// 모래 위치 업데이트
void SpreadSand(int x, int y, int dir) {
	int sand = grid[y][x];
	grid[y][x] = 0;
	// 모래가 없으면 나가면 됨
	if (sand == 0)
		return;

	// 퍼진 모래 합
	int sand_hap = 0;

	// 모래 분산 시작
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			// 마스크 위치
			int next_x = x + (j - 2);
			int next_y = y + (i - 2);

			// 마스크 위치 변수
			int r, c;
			// 마스크 회전
			switch (dir) {
			case 0:
				r = i, c = j;
				break;
			case 1:
				r = j, c = 4 - i;
				break;
			case 2:
				r = 4 - i; c = 4 - j;
				break;
			case 3:
				r = 4 - j, c = i;
				break;
			}

			int percent = sand_mask[r][c];
			// 퍼센트가 0이면 패스
			if (percent == 0)
				continue;

			// 퍼진 모래 계산
			int spread = sand * percent / 100;
			sand_hap += spread;

			// 퍼진 모래 적용
			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) {
				result += spread;
			}
			else {
				grid[next_y][next_x] += spread;
			}	
		}
	}

	// a자리 모래 채우기
	int next_x = x + dx[dir];
	int next_y = y + dy[dir];
	int remainder = sand - sand_hap;

	if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) {
		result += remainder;
	}
	else {
		grid[next_y][next_x] += remainder;
	}
}

int main() {
	cin >> n;
	grid = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	// 토네이도 위치
	int x = n / 2;
	int y = n / 2;

	// 이동거리 및 이동방향
	int move = 1, dir = 0;

	while (true) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < move; j++){
				// 다음 위치 찾기
				int next_x = x + dx[dir];
				int next_y = y + dy[dir];

				// 모래 변경
				SpreadSand(next_x, next_y, dir);

				// 토네이토 위치 변경
				x = next_x;
				y = next_y;

				// 결과값 출력
				if (x == 0 && y == 0) {
					cout << result << "\n";
					return 0;
				}
			}

			dir = (dir + 1) % 4;
		}
		move++;
	}

	return 0;
}