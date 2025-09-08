#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> numbers;
vector<int> result;
vector<bool> visited;

void BackTracking(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	int prev = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && prev != numbers[i]) {
			visited[i] = true;
			result.push_back(numbers[i]);
			prev = numbers[i];

			BackTracking(depth + 1);

			result.pop_back();
			visited[i] = false;
		}
		
	}
}

int main() {
	cin >> n >> m;
	numbers = vector<int>(n);
	visited = vector<bool>(n, false);

	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());

	BackTracking(0);

	return 0;
}