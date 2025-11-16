#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string gear1, gear2;
	cin >> gear1;
	cin >> gear2;

	int gear1_len = gear1.length();
	int gear2_len = gear2.length();

	int min_len = gear1_len + gear2_len;

	for (int i = -gear2_len; i <= gear1_len; i++) {
		bool is_able = true;

		for (int j = 0; j < gear2_len; j++) {
			int gear1_index = i + j;

			if (gear1_index >= 0 && gear1_index < gear1_len) {
				if (gear1[gear1_index] == '2' && gear2[j] == '2') {
					is_able = false;
					break;
				}
			}
		}

		if (is_able) {
			int start = min(0, i);
			int end = max(gear1_len, i + gear2_len);
			int current_len = end - start;

			min_len = min(min_len, current_len);
		}
	}

	cout << min_len << "\n";

	return 0;
}