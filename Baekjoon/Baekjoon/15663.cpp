#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> numbers;
vector<int> result;

void BackTracking(int start, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < n; i++) {
		result.push_back(numbers[i]);
		BackTracking(i + 1, depth + 1);
		result.pop_back();
	}
}

int main() {
	cin >> n >> m;
	numbers = vector<int>(n);

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());

	BackTracking(0, 0);

	return 0;
}