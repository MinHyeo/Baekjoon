#include <iostream>
#include <string>
using namespace std;

int main() {
	string input[3];
	for (int i = 0; i < 3; i++) {
		cin >> input[i];
	}

	int idx;
	int num;
	for (int i = 0; i < 3; i++) {
		if (isdigit(input[i][0])) {
			idx = i;
			num = stoi(input[i]);
		}
	}

	int result = num + (3 - idx);
	if (result % 3 == 0 && result % 5 == 0) {
		cout << "FizzBuzz" << "\n";
	}
	else if (result % 3 == 0) {
		cout << "Fizz" << "\n";
	}
	else if (result % 5 == 0) {
		cout << "Buzz" << "\n";
	}
	else {
		cout << result << "\n";
	}

	return 0;
}