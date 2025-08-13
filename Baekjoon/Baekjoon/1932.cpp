#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> v;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> input;
		for (int j = 0; j < i + 1; j++) {
			int a;
			cin >> a;
			input.push_back(a);
		}

		v.push_back(input);
	}

	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				v[i][j] += v[i - 1][j];
			else if (j == i)
				v[i][j] += v[i - 1][j - 1];
			else
				v[i][j] += max(v[i - 1][j - 1], v[i - 1][j]);
		}
	}

	cout << *max_element(v[n - 1].begin(), v[n - 1].end()) << "\n";

	return 0;
}