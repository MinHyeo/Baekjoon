#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define WHEEL_MAX_SIZE 4
#define WHHEL_TOOTH_SIZE 8

vector<vector<int>> toothedWheel;

void TurnWheel(int index, int dir, int count) {
	if (count >= 0 && index + 1 < WHEEL_MAX_SIZE) {
		if (toothedWheel[index][2] != toothedWheel[index + 1][6]) {
			TurnWheel(index + 1, dir * -1, count + 1);
		}
	}
	if (count <= 0 && index - 1 >= 0) {
		if (toothedWheel[index][6] != toothedWheel[index - 1][2]) {
			TurnWheel(index - 1, dir * -1, count - 1);
		}
	}

	if (dir == 1) {
		int state = toothedWheel[index].back();
		toothedWheel[index].pop_back();
		toothedWheel[index].insert(toothedWheel[index].begin(), state);
	}
	else {
		int state = toothedWheel[index][0];
		toothedWheel[index].erase(toothedWheel[index].begin());
		toothedWheel[index].push_back(state);
	}
}

int main() {
	toothedWheel = vector<vector<int>>(4, vector<int>(8, 0));

	for (int i = 0; i < WHEEL_MAX_SIZE; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < WHHEL_TOOTH_SIZE; j++) {
			toothedWheel[i][j] = input[j] - '0';
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num, dir;
		cin >> num >> dir;

		TurnWheel(num - 1, dir, 0);
	}

	int result = 0;
	for (int i = 0; i < WHEEL_MAX_SIZE; i++) {
		result += toothedWheel[i][0] * pow(2, i);
	}
	cout << result << "\n";

	return 0;
}