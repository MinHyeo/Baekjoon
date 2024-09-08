#include <iostream>
#include <cmath>

#pragma region �����
#define BROKENBUTTON 10
#define CURRENTNUMBER 100
#pragma endregion

using namespace std;

//1. + / -��ư���θ� �̵��� �����Ѱ� ?
//2. target number ���� ū / ���� ���ڸ� �Է��ؾ��ϴ��� �Ǵ�
//3.

//��ȣ ũ�� ���ϴ� �Լ�
int GetDigitCount(int number);
//+/-��ư���θ� �̵��� �������� �Ǵ�
bool DecideOnlyButton(int targetNum);

int main() {
	int result = 0;
	int targetNum;
	int brokenCount; 
	int brokenNum[BROKENBUTTON];

	cin >> targetNum;
	cin >> brokenCount;

	//�μ��� ���ڹ�ư
	for (int index = 0; index < brokenCount; index++) {
		cin >> brokenNum[index];
	}

	// +/-��ư���θ� �̵��� �������� �Ǵ�
	if (DecideOnlyButton(targetNum)) {
		cout << abs(targetNum - CURRENTNUMBER) << endl;
	}
	else {
		//�̵��Ϸ��� �ϴ� ä�κ��� ū/���� ���ڸ� �Է��ؾ��ϴ��� �Ǵ�

	}

	return 0;
}

int GetDigitCount(int number) {
	if (number == 0) return 1;
	return static_cast<int>(log10(abs(number)) + 1);
}

bool DecideOnlyButton(int targetNum) {
	int numLen = GetDigitCount(targetNum);
	int subNum = abs(targetNum - CURRENTNUMBER);

	if (subNum <= numLen)
		return true;
	
	return false;
}