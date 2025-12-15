#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> numbers(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}
	
	vector<int> result;
	vector<bool> is_visited(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (is_visited[i])
			continue;

		stack<int> s;
		vector<bool> is_checked(n + 1, false);
		int next_index = i;
		while (!is_visited[next_index]) {
			s.push(next_index);
			is_visited[next_index] = true;
			is_checked[next_index] = true;

			next_index = numbers[next_index];
			if (is_visited[next_index] && is_checked[next_index]) {
				while (!s.empty()) {
					int num = s.top(); s.pop();
					result.push_back(num);

					if (num == next_index)
						break;
				}
			}

		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int num : result) {
		cout << num << "\n";
	}

	return 0;
}