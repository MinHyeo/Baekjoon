#include<iostream>
#include<algorithm>

using namespace std;

int binary_search(long long n, long long k, long long cable[], long long min, long long max) {
	long long result = 0;

	while (min <= max) {
		int cable_count = 0;
		//만들 수 있는 케이블 수 체크
		long long mid = (min + max) / 2;

		int array_length = k;
		for (int i = 0; i < array_length; i++) {
			cable_count += cable[i] / mid;
		}

		if (cable_count >= n) {
			result = mid;
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}

	return result;
}

int main() {
	//입출력 시간 단축
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//입력
	long long k, n;
	cin >> k >> n;

	//케이블 길이 배열
	long long cable[10000];

	for (int i = 0; i < k; i++) {
		cin >> cable[i];
	}

	long long result;		//결과값
	long long max;		//케이블 길이 최소값

	//이진탐색
	max = *max_element(cable, cable + k);
	result = binary_search(n, k, cable, 1, max);

	cout << result << endl;

	return 0;
}