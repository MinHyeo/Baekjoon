#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> numbers(n + 1);
	vector<int> sort_numbers(n + 1);
	map<int, int> pos;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
		sort_numbers[i] = numbers[i];
		pos[numbers[i]] = i;
	}
	sort(sort_numbers.begin() + 1, sort_numbers.end());

	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		if (numbers[i] != sort_numbers[i]) {
			int current_num = numbers[i];
			int target_num = sort_numbers[i];
			int target_pos = pos[target_num];

			swap(numbers[i], numbers[target_pos]);

			pos[i] = i;
			pos[current_num] = target_pos;

			cnt++;
			if (cnt == k) {
				for (int j = 1; j <= n; j++)
					cout << numbers[j] << " ";
				cout << "\n";
				return 0;
			}
		}
	}
	cout << -1 << "\n";

	return 0;
}