#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct Computer {
	int index;
	int rank;
	int speed;
};

int main() {
	int n;
	cin >> n;

	vector<Computer> computers;
	vector<vector<int>> ranks(n + 1, vector<int>());
	int max_rank = 0;
	for (int i = 0; i < n; i++) {
		int rank, speed;
		cin >> rank >> speed;

		computers.push_back({ i, rank, speed });
		ranks[rank].push_back(i);
		max_rank = max(max_rank, rank);
	}

	int result = 0;
	for (int i = 2; i <= max_rank; i++) {
		int max_speed = 0;
		for (int j : ranks[i]) {
			Computer cur_computer = computers[j];

			for (int k : ranks[i - 1]) {
				Computer pre_computer = computers[k];

				int time = pow(cur_computer.index - pre_computer.index, 2) + pre_computer.speed;
				max_speed = max(max_speed, time);
			}
		}

		result += max_speed;
	}

	cout << result << "\n";

	return 0;
}