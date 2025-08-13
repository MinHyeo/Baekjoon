#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int minValue[2][3] = { 0, 0, 0, INT_MAX, INT_MAX, INT_MAX };
	int maxValue[2][3] = { 0,0,0, 0,0,0 };
	int index = 0;

	for (int i = 0; i < n; i++) {
		int num[3];
		cin >> num[0] >> num[1] >> num[2];

		for (int j = 0; j < 3; j++) {
			if (j != 0) {
				maxValue[1 - index][j - 1] = max(maxValue[index][j] + num[j - 1], maxValue[1 - index][j - 1]);
				minValue[1 - index][j - 1] = min(minValue[index][j] + num[j - 1], minValue[1 - index][j - 1]);
			}

			maxValue[1 - index][j] = max(maxValue[index][j] + num[j], maxValue[1 - index][j]);
			minValue[1 - index][j] = min(minValue[index][j] + num[j], minValue[1 - index][j]);

			if (j != 2) {
				maxValue[1 - index][j + 1] = max(maxValue[index][j] + num[j + 1], maxValue[1 - index][j + 1]);
				minValue[1 - index][j + 1] = min(minValue[index][j] + num[j + 1], minValue[1 - index][j + 1]);
			}
		}

		for (int j = 0; j < 3; j++) {
			minValue[index][j] = INT_MAX;
		}
		index = 1 - index;
	}

	
	

	cout << *max_element(maxValue[index], maxValue[index] + 3) << " " << *min_element(minValue[index], minValue[index] + 3) << "\n";

	return 0;
}