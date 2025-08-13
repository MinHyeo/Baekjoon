#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> numbers;
vector<int> v;

void backTracking(int start, int depth) {
	if (depth == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < n; i++) {
		if (find(v.begin(), v.end(), numbers[i]) != v.end())
			continue;

		v.push_back(numbers[i]);
		backTracking(0, depth + 1);
		v.pop_back();
	}
}

int main() {

	cin >> n >> m;

	numbers = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());

	backTracking(0, 0);

	return 0;
}