#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	string result = "";
	int count = 0;
	for (int i = 0; i <= s.size(); i++) {
		if (i == s.size() || s[i] == '.') {
			if (count % 2 != 0) {
				cout << -1 << "\n";
				return 0;
			}

			for (int j = 0; j < count / 4; j++)
				result += "AAAA";
			for (int j = 0; j < (count % 4) / 2; j++)
				result += "BB";

			if (i < s.size())
				result += '.';
			count = 0;
		}
		else {
			count++;
		}
	}

	cout << result << "\n";

	return 0;
}