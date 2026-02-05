#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int sum = 0;
	int pos = -1;

	for (int i = 0; i < 13; i++) {
		if (s[i] == '*') {
			pos = i;
			continue;
		}
		int num = s[i] - '0';
		if ((i + 1) % 2 == 1)
			sum += num;
		else
			sum += num * 3;
	}

	for (int i = 0; i < 10; i++) {
		int temp = sum;
		if ((pos + 1) % 2)
			temp += i;
		else
			temp += i * 3;

		if (temp % 10 == 0) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}