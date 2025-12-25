#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> array(n, vector<int>(5));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> array[i][j];
		}
	}

	int result = 0;
	int max_count = -1;

	for (int i = 0; i < n; i++) {
		int count = 0;

		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;

			for (int k = 0; k < 5; k++) {
				if (array[i][k] == array[j][k]) {
					count++;
					break;
				}
			}
		}

		if (count > max_count) {
			max_count = count;
			result = i;
		}
	}

	cout << result + 1 << "\n";

	return 0;
}