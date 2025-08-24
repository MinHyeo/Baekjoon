#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int index = 1;
	stack<int> s;
	vector<char> result;
	for (int i = 0; i < n; i++) {
		while (index <= v[i]) {
			s.push(index++);
			result.push_back('+');
		}

		if (s.top() != v[i]) {
			cout << "NO" << "\n";
			return 0;
		}
		result.push_back('-');
		s.pop();
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}