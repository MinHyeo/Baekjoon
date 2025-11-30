#include <iostream>
#include <vector>
using namespace std;

int main() {
	string name;
	cin >> name;

	int alphabet[26] = { 0 };
	for (char c : name) {
		alphabet[c - 'A'] += 1;
	}

	int index = 0;
	vector<char> result(name.length(), ' ');
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == 0)
			continue;

		if (alphabet[i] % 2 != 0) {
			if (name.length() % 2 == 0) {
				cout << "I'm Sorry Hansoo" << "\n";
				return 0;
			}

			if (result[name.length() / 2] == ' ') {
				result[name.length() / 2] = i + 'A';
				alphabet[i]--;
			}
			else {
				cout << "I'm Sorry Hansoo" << "\n";
				return 0;
			}
		}

		if (alphabet[i] % 2 == 0) {
			for(int j = 0;j < alphabet[i] / 2;j++){
				result[index] = i + 'A';
				result[name.length() - (index + 1)] = i + 'A';
				index++;
			}
		}
	}

	for (char c : result) {
		cout << c;
	}
	cout << "\n";

	return 0;
}