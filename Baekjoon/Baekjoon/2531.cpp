#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, d, k, c;
	cin >> n >> d >> k >> c;

	// 쿠폰 스시가 존재하는가?
	bool is_coupon_sushi = false;
	vector<int> sushi(n);
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
		// 쿠폰 스시가 존재한다면 true로 바꾸기
		if (sushi[i] == c)
			is_coupon_sushi = true;
	}

	// 브루트포스 시작
	int max_kind = 0;
	for (int i = 0; i < n; i++) {
		// 길이 저장 변수
		int kind = 0;
		// 초밥 종류에 따라 먹었는지 체크용 변수
		vector<bool> is_eat(d + 1, false);

		// i부터 k번째 초밥까지 먹기
		for (int j = 0; j < k; j++) {
			int index = (i + j) % n;
			// 아직 안 먹은 초밥일 경우
			if (!is_eat[sushi[index]]) {
				// 가짓수 늘리고 먹었다고 표시
				kind += 1;
				is_eat[sushi[index]] = true;
			}
		}

		// 쿠폰 초방이 포함되어 있지 않으면 추가
		if (!is_eat[c])
			kind += 1;

		// 최대 가짓수 업데이트
		max_kind = max(max_kind, kind);
	}

	cout << max_kind << "\n";

	return 0;
}