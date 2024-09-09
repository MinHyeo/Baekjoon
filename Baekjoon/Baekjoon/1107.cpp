#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#pragma region �����
#define BROKENBUTTON 10
#define CURRENTNUMBER 100
#define MAXNUMBERLENGTH 6
#pragma endregion

using namespace std;

//1. + / -��ư���θ� �̵��� �����Ѱ� ?
//2. target number ���� ū / ���� ���ڸ� �Է��ؾ��ϴ��� �Ǵ�
//3. 

//��ȣ ũ�� ���ϴ� �Լ�
int GetDigitCount(int number);
//+/-��ư���θ� �̵��� �������� �Ǵ�
bool DecideOnlyButton(int targetNum);
//������ �ڸ� �� ����
template <typename T>
vector<T> GetDigits(T number);
//��ǥ ä�� ���� ���峭 ��ư�� �ִ��� Ȯ��
bool *CheckTargetNumber(int targetNum, int brokenNum[]);

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
		bool* brokenNumberPosition = CheckTargetNumber(targetNum, brokenNum);

	}

	return 0;
}

///<summary> ������ �ڸ����� ���ϴ� �Լ� </summary>
int GetDigitCount(int number) {
	if (number == 0) return 1;
	return static_cast<int>(log10(abs(number)) + 1);
}
/// <summary>+/-��ư���θ� �̵��� �������� �Ǵ�</summary>
bool DecideOnlyButton(int targetNum) {
	int numLen = GetDigitCount(targetNum);
	int subNum = abs(targetNum - CURRENTNUMBER);

	if (subNum <= numLen)
		return true;
	
	return false;
}
///<summary>������ �ڸ� �� ����</summary>
template <typename T>
vector<T> GetDigits(T number) {
	vector<T> digits;

	while (number > 0) {
		digits.push_back(number % 10);
		number /= 10;
	}

	reverse(digits.begin(), digits.end());

	return digits;
}
/// <summary>��ǥ ä�ο� ���峭 ��ư�� ���ڰ� �����ϴ��� üũ</summary>
bool *CheckTargetNumber(int targetNum, int brokenNum[]) {
	vector<int> targetNumber = GetDigits<int>(targetNum);
	int targetNumberLength = GetDigitCount(targetNum);
	int brokenNumberLength = sizeof(brokenNum) / sizeof(*brokenNum);

	bool brokenNumberPosition[MAXNUMBERLENGTH];

	for (int i = 0; i < targetNumberLength; i++) {
		for (int j = 0;j < brokenNumberLength; j++) {
			if (targetNumber[i] == brokenNum[j]) {
				brokenNumberPosition[i] = true;
				break;
			}

			brokenNumberPosition[i] = false;
		}
	}

	return brokenNumberPosition;
}
