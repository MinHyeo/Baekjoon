#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> numbers(n);
	long long hap = 0;
	int count_num[8001] = { 0, };
	int min_num = 4000, max_num = -4000;

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		hap += numbers[i];
		count_num[numbers[i] + 4000]++;

		min_num = min(min_num, numbers[i]);
		max_num = max(max_num, numbers[i]);
	}

	sort(numbers.begin(), numbers.end());

	int max_count = 0;
	vector<int> max_count_numbers;
	for (int i = 0; i <= 8000; i++) {
		if (count_num[i] > max_count) {
			max_count = count_num[i];
			max_count_numbers.clear();
			max_count_numbers.push_back(i - 4000);
		}
		else if (count_num[i] == max_count) {
			max_count_numbers.push_back(i - 4000);
		}
	}
	int mode_number = 0;
	if (max_count_numbers.size() == 1) {
		mode_number = max_count_numbers[0];
	}
	else {
		mode_number = max_count_numbers[1];
	}

	cout << (int)round((double)hap / n) << "\n";
	cout << numbers[n / 2] << "\n";
	cout << mode_number << "\n";
	cout << max_num - min_num << "\n";

	return 0;
}