#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> top(n);
	for (int i = 0; i < n; i++) {
		cin >> top[i];
	}

	vector<int> result(n, 0);
	stack<pair<int, int>> s;
	for (int i = 0; i < n; i++) {
		int height = top[i];

		while (!s.empty() && s.top().first < height) {
			s.pop();
		}

		if (!s.empty())
			result[i] = s.top().second;

		s.push({ height, i + 1 });
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}