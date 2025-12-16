#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;

	vector<int> numbers(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		numbers[i] = numbers[i - 1] + num;
	}

	int min_result = 1e9;
	int left = 0, right = 0;
	while (right <= n) {
		if (numbers[right] - numbers[left] >= s) {
			min_result = min(min_result, right - left);
			left += 1;
		}
		else {
			right += 1;
		}
	}

	if (min_result == 1e9)
		min_result = 0;
	cout << min_result << "\n";

	return 0;
}