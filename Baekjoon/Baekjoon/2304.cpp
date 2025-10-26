#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> pillars(n);
	for (int i = 0; i < n; i++) {
		cin >> pillars[i].first >> pillars[i].second;
	}

	sort(pillars.begin(), pillars.end());

	int max_h = 0, max_index = 0;
	for (int i = 0; i < n; i++) {
		if (pillars[i].second > max_h) {
			max_h = pillars[i].second;
			max_index = i;
		}
	}

	int area = 0;
	int left_max = pillars[0].second;
	int left_pos = pillars[0].first;
	for (int i = 1; i <= max_index; i++) {
		if (pillars[i].second >= left_max) {
			area += (pillars[i].first - left_pos) * left_max;
			left_pos = pillars[i].first;
			left_max = pillars[i].second;
		}
	}

	int right_max = pillars[n - 1].second;
	int right_pos = pillars[n - 1].first;
	for (int i = n - 2; i >= max_index; i--) {
		if (pillars[i].second >= right_max) {
			area += (right_pos - pillars[i].first) * right_max;
			right_pos = pillars[i].first;
			right_max = pillars[i].second;
		}
	}

	area += max_h;
	cout << area << "\n";

	return 0;
}