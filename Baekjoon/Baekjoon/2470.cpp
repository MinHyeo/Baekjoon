#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> solutions(n);
	for (int i = 0; i < n; i++) {
		cin >> solutions[i];
	}
	sort(solutions.begin(), solutions.end());

	int minSum = INT32_MAX;
	int left = 0, right = n - 1;
	pair<int, int> result = { 0, 0 };
	while (left < right) {
		int sum = solutions[left] + solutions[right];

		if (abs(sum) < minSum) {
			minSum = abs(sum);
			result = { left, right };
		}
		if (sum < 0) {
			left += 1;
		}
		else {
			right -= 1;
		}
	}

	cout << solutions[result.first] << " " << solutions[result.second] << "\n";

	return 0;
}