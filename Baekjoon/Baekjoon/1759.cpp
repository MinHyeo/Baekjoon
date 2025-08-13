#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> alphabets;
vector<char> secretCode;

bool CheckSecretCode() {
	int count = 0;
	bool isVowel = false;

	for (char c : secretCode) {
		if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
			count++;
		}
		else {
			isVowel = true;
		}
	}


	return (count >= 2) && isVowel;
}

void MakeSecretCode(int start, int depth) {
	if (depth == l) {
		if (!CheckSecretCode())
			return;

		for (int i = 0; i < l; i++) {
			cout << secretCode[i]; 
		}
		cout << "\n";

		return;
	}

	for (int i = start; i < c; i++) {
		secretCode.push_back(alphabets[i]);
		MakeSecretCode(i + 1, depth + 1);
		secretCode.pop_back();
	}
}

int main() {
	cin >> l >> c;

	alphabets = vector<char>(c);
	for (int i = 0; i < c; i++) {
		cin >> alphabets[i];
	}
	sort(alphabets.begin(), alphabets.end());

	MakeSecretCode(0, 0);

	return 0;
}