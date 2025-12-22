#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> numbers;
vector<int> result;

void BackTracking(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int number : numbers) {
		result.push_back(number);
		BackTracking(depth + 1);
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
	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

	BackTracking(0);

	return 0;
}