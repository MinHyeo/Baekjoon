#include <iostream>
using namespace std;

int main() {
	string oct;
	cin >> oct;

	string bin[8] = {
		"000", "001", "010", "011",
		"100", "101", "110", "111"
	};

	bool first = true;
	for (char c : oct) {
		int num = c - '0';
		if (first) {
			string b = bin[num];
			int index = b.find("1");
			if (index == string::npos)
				cout << "0";
			else
				cout << b.substr(index);
			first = false;
		}
		else
			cout << bin[num];
	}

	return 0;
}