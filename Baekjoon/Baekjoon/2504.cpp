#include <iostream>
#include <stack>
using namespace std;

int main() {
	string input;
	cin >> input;

	stack<char> s;
	int result = 0;
	int temp = 1;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			s.push(input[i]);
			temp *= 2;
		}
		else if (input[i] == '[') {
			s.push(input[i]);
			temp *= 3;
		}
		else if (input[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0 << "\n";
				return 0;
			}

			if(input[i - 1] == '[' || input[i - 1] == '(')
				result += temp;
			temp /= 2;
			s.pop();
		}
		else if (input[i] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0 << "\n";
				return 0;
			}

			if(input[i - 1] == '[' || input[i - 1] == '(')
				result += temp;
			temp /= 3;
			s.pop();
		}
	}

	if (!s.empty()) 
		cout << 0 << "\n";
	else
		cout << result << "\n";

	return 0;
}