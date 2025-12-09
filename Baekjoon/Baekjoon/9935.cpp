#include <iostream>
#include <map>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s, bomb_s;
	cin >> s;
	cin >> bomb_s;

	string result = "";
	stack<char> stack;

	map<char, bool> map;
	for (char c : bomb_s) {
		map[c] = true;
	}

	for (char c : s) {
		result += c;

		if (map[c]) {
			if (result.size() >= bomb_s.size()) {
				string new_s = "";
				for (int i = 1; i <= bomb_s.size(); i++) {
					new_s = result[result.size() - 1] + new_s;
					result.pop_back();
				}

				if (new_s != bomb_s) {
					result += new_s;
				}
			}
		}
		//if (!map[c]) {
		//	string stack_s = "";
		//	while (!stack.empty()) {
		//		char stack_c = stack.top(); stack.pop();
		//		stack_s = stack_c + stack_s;
		//	}
		//	result += (stack_s + c);
		//}
		//else {
		//	stack.push(c);
		//	if (bomb_s.size() <= stack.size()) {
		//		string new_s = "";
		//		while (!stack.empty()) {
		//			char stack_c = stack.top(); stack.pop();
		//			new_s = (stack_c + new_s);

		//			if (new_s.size() == bomb_s.size())
		//				break;
		//		}

		//		if (new_s != bomb_s) {
		//			for (char new_c : new_s) {
		//				stack.push(new_c);
		//			}
		//		}
		//	}
		//}
	}

	//string stack_s;
	//while (!stack.empty()) {
	//	char stack_c = stack.top(); stack.pop();
	//	stack_s = stack_c + stack_s;
	//}
	//result += stack_s;

	if (result == "")
		cout << "FRULA" << "\n";
	else
		cout << result << "\n";

	return 0;
}