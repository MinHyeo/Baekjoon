#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	int count = 0;
	int num = 666;

	while (true) {
		string s = to_string(num);
		if (s.find("666") != string::npos) {
			count++;
			if (count == n) {
				cout << num << "\n";
				break;
			}
		}

		num++;
	}

	return 0;
}