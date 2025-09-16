#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second >= b.second) {
		return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> works;
	for (int i = 0; i < n; i++) {
		int t, s;
		cin >> t >> s;
		works.push_back({ t, s });
	}

	sort(works.begin(), works.end(), compare);
	vector<int> timer(works[n - 1].second, 0);

	for (int i = n - 1; i >= 0; i--) {
		int count = 0;
		for (int j = 1; j <= works[i].first;) {
			if (works[i].second - j - count < 0) {
				cout << "-1" << "\n";
				return 0;
			}

			if (timer[works[i].second - j - count] == 0) {
				timer[works[i].second - j - count] = 1;
				j++;
			}
			else {
				count++;
			}
		}
	}

	int result = 0;
	for (int i = 0; true; i++) {
		if (timer[i] == 0)
			result++;
		else
			break;
	}

	cout << result << "\n";

	return 0;
}