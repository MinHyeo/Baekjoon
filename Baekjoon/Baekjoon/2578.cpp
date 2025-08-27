#include <iostream>
#include <vector>
using namespace std;

int bingo[5][5];
bool isErase[5][5];

int Bingo() {
	int count = 0;
	bool isBingo;

	for (int i = 0; i < 5; i++) {
		isBingo = true;
		for (int j = 0; j < 5; j++) {
			if (!isErase[i][j]) {
				isBingo = false;
				break;
			}
		}

		if (isBingo)
			count++;
	}

	for (int i = 0; i < 5; i++) {
		isBingo = true;
		for (int j = 0; j < 5; j++) {
			if (!isErase[j][i]) {
				isBingo = false;
				break;
			}
		}

		if (isBingo)
			count++;
	}

	isBingo = true;
	for (int i = 0; i < 5; i++) {
		if (!isErase[i][i]) {
			isBingo = false;
			break;
		}
	}
	if (isBingo)
		count++;

	isBingo = true;
	for (int i = 0; i < 5; i++) {
		if (!isErase[i][4 - i]) {
			isBingo = false;
			break;
		}
	}
	if (isBingo)
		count++;

	return count;
}

void EraseNum(int num) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j] == num) {
				isErase[i][j] = true;
				return;
			}
		}
	}
}

int main() {


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> bingo[i][j];
			isErase[i][j] = false;
		}
	}

	int call[25];
	for (int i = 0; i < 25; i++) {
		cin >> call[i];
	}

	for (int i = 0; i < 25; i++) {
		EraseNum(call[i]);

		if (Bingo() >= 3) {
			cout << i + 1 << "\n";
			break;
		}
	}

	return 0;
}