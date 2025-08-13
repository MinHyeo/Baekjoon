#include <iostream>
using namespace std;

int main() {
	int L, R;
	cin >> L >> R;

	int count = 0, result = 0;

	while (L != 0 || R != 0) {
		int l = L % 10;
		int r = R % 10;
		count++;

		if (l == r) {
			// 만약 l과 r이 8로 같으면 결과값 증가
			if (l == 8)
				result++;
		}
		else {
			result = 0;
		}

		L /= 10;
		R /= 10;
	}

	cout << result << endl;
}