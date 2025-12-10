#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> lines(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		lines[i] = { x, y };
	}
	sort(lines.begin(), lines.end());

	int begin_point = lines[0].first;
	int end_point = lines[0].second;
	int last_line = end_point - begin_point;
	int result = 0;

	for (int i = 1; i < n; i++) {
		if (lines[i].first <= end_point) {
			end_point = max(end_point, lines[i].second);
			last_line = end_point - begin_point;
		}
		else {
			begin_point = lines[i].first;
			end_point = lines[i].second;
			result += last_line;
			last_line = end_point - begin_point;
		}
	}
	
	result += last_line;
	cout << result << "\n";

	return 0;
}