#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int alphbet[26] = { 0 };
	for (char c : s) {
		alphbet[c - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << alphbet[i] << " ";
	}
	cout << "\n";

	return 0;
}