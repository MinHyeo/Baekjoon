#include <iostream>
#include <stack>
using namespace std;

int main() {
	string stick;
	cin >> stick;

	stack<char> s;
	int result = 0;
	bool is_back_closed = false;;
	for (char c : stick) {
		if (c == '(') {
			s.push('(');
			is_back_closed = false;
		}
		else {
			s.pop();

			if (!is_back_closed) {
				is_back_closed = true;
				result += s.size();
			}
			else {
				result += 1;
			}
		}
	}

	cout << result << "\n";

	return 0;
}