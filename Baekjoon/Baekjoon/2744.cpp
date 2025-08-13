#include <iostream>
#include <cctype>
using namespace std;

int main() {
	string inputStr;
	cin >> inputStr;

	for (int i = 0; i < inputStr.size(); i++) {
		if (isupper(inputStr[i])) {
			inputStr[i] = tolower(inputStr[i]);
		}
		else {
			inputStr[i] = toupper(inputStr[i]);
		}
	}

	cout << inputStr << "\n";

	return 0;
}