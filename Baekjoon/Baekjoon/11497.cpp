#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> trees(n);
		for (int i = 0; i < n; i++) {
			cin >> trees[i];
		}

		sort(trees.begin(), trees.end());

		vector<int> new_array(n);
		for (int i = 0; i < n; i++) {
			int index = (i % 2) == 0 ? (i / 2) : (n - 1) - (i / 2);
			new_array[index] = trees[i];
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			int next_index = (i + 1) % n;
			int before_index = (n + (i - 1)) % n;
			result = max(result, abs(new_array[i] - new_array[next_index]));
			result = max(result, abs(new_array[i] - new_array[before_index]));
		}
		cout << result << "\n";
	}

	return 0;
}