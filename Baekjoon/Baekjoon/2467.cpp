#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> solutions(n);
	for (int i = 0; i < n; i++) {
		cin >> solutions[i];
	}

	long long front = 0, back = n - 1;
	long long min_sum = 1e19;
	int result_i = front, result_j = back;
	while (front < back) {
		long long sum = solutions[back] + solutions[front];

		if (abs(min_sum) > abs(sum)) {
			min_sum = sum;
			result_i = front;
			result_j = back;
		}

		if (sum > 0) {
			back--;
		}
		else {
			front++;
		}
	}

	cout << solutions[result_i] << " " << solutions[result_j] << "\n";

	return 0;
}