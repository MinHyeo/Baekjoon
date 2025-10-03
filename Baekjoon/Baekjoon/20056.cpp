#include <iostream>
#include <vector>
using namespace std;

struct FireBall {
	int r, c;
	int m;
	int s;
	int d;
};

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	vector<FireBall> fireball_list;
	// 파이어볼 초기값 입력
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireball_list.push_back(FireBall{ r - 1, c - 1, m, s, d });
	}

	// 이동 방향 정의
	int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

	// 파이어볼 이동 시작
	for (int i = 0; i < K; i++) {
		vector<vector<vector<FireBall>>> map(N, vector<vector<FireBall>>(N));
		// 파이어볼 이동
		for (auto& fireball : fireball_list) {
			int step = fireball.s % N;
			int next_r = (fireball.r + dy[fireball.d] * step + N) % N;
			int next_c = (fireball.c + dx[fireball.d] * step + N) % N;

			fireball.r = next_r;
			fireball.c = next_c;
			map[fireball.r][fireball.c].push_back(fireball);
		}

		// 파이어볼 합치기
		vector<FireBall> next_list;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				// 현재 위치에 파이어볼이 없으면 패스
				if (map[j][k].empty())
					continue;

				int fireball_count = map[j][k].size();
				// 파이어볼이 2개 이상일 경우
				if (fireball_count >= 2) {
					int sum_m = 0;
					int sum_s = 0;
					bool is_even = true;	//짝수인가?
					bool is_odd = true;		//홀수인가?

					// 파이어볼 합치기
					for (auto& fireball : map[j][k]) {
						sum_m += fireball.m;
						sum_s += fireball.s;

						if (fireball.d % 2 == 0) is_odd = false;
						else is_even = false;
					}
					int new_m = sum_m / 5;
					// 질량이 0이면 소멸
					if (new_m == 0) continue;
					int new_s = sum_s / fireball_count;
					int dir = (is_even || is_odd) ? 0 : 1;
					// 새로운 파이어볼 생성
					for (int l = 0; l < 4; l++) {
						next_list.push_back(FireBall{ j, k, new_m, new_s, l * 2 + dir });
					}
				}
				else {	// 파이어볼이 2개 미만일 경우
					next_list.push_back(map[j][k][0]);
				}
			}
		}
		fireball_list = move(next_list);
	}

	int result = 0;
	for (auto& fireball : fireball_list) {
		result += fireball.m;
	}
	cout << result << "\n";

	return 0;
}