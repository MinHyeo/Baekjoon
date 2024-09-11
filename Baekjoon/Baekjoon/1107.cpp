#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#pragma region 상수값
#define BROKENBUTTON 10
#define CURRENTNUMBER 100
#define MAXNUMBERLENGTH 6
#pragma endregion

using namespace std;

//��ȣ ũ�� ���ϴ� �Լ�
int GetDigitCount(int number);
//+/-��ư���θ� �̵��� �������� �Ǵ�
bool DecideOnlyButton(int targetNum);
//������ �ڸ� �� ����
template <typename T>
vector<T> GetDigits(T number);
//��ȣ�� ���峭 ��ư���� üũ
bool CheckBrokenNumber(int number, int brokenNum[]);
//��ǥ ä�� ���� ���峭 ��ư�� �ִ��� Ȯ��
bool *CheckTargetNumber(int targetNum, int brokenNum[]);
int FindNumber(int number, int brokenNum[]);
//
vector<int> FindOptimumNumber(int targetNum, int brokenNum[], bool* brokenNumPos);

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

		//üũ�� ���ڰ� (Ŀ����/�۾�����) �� ���� ���ڴ� ���� (���� ��/ū ��)�� ������ ��
		//특정 위치의 숫자가 (커지면/작아지면) 다음 숫자들은 (가장 작은/가장 큰) 숫자가 되어야 한다.

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
/// <summary>��ȣ�� ���峭 ��ư���� üũ</summary>
bool CheckBrokenNumber(int number, int brokenNum[]) {
	int brokenNumberLength = sizeof(brokenNum) / sizeof(*brokenNum);

	for (int i = 0; i < brokenNumberLength; i++) {
		if (number == brokenNum[i]) {
			return true;
		}
	}
	return false;
}
/// <summary>��ǥ ä�ο� ���峭 ��ư�� ���ڰ� �����ϴ��� üũ</summary>
bool *CheckTargetNumber(int targetNum, int brokenNum[]) {
	vector<int> targetNumber = GetDigits<int>(targetNum);
	//int targetNumberLength = GetDigitCount(targetNum);
	int targetNumberLength = targetNumber.size();
	int brokenNumberLength = sizeof(brokenNum) / sizeof(*brokenNum);

	bool brokenNumberPosition[MAXNUMBERLENGTH];

	for (int i = 0; i < targetNumberLength; i++) {
		brokenNumberPosition[i] = CheckBrokenNumber(targetNumber[i], brokenNum);
	}

	return brokenNumberPosition;
}
int FindNumber(int number, int brokenNum[]){
	int result = number;
	bool isUp = true;

	if(CheckBrokenNumber(result + 1, brokenNum)){
		return number;
	}

	if(isUp){
		result = FindNumber(number + 1, brokenNum);
	}
	else{

	}
	return result;
}
vector<int> FindOptimumNumber(int targetNum, int brokenNum[], bool* brokenNumPos){
	vector<int> targetNumber = GetDigits<int>(targetNum);
	int targetNumberLength = targetNumber.size();
	vector<int> resultNumber;
	bool isBroken = false;

	for(int i = 0; i < targetNumberLength; i++){
		if(!brokenNumPos[i]){
			resultNumber.push_back(targetNumber[i]);
			continue;
		}

		if(CheckBrokenNumber(targetNumber[i], brokenNum)){
				isBroken = true;
				int number = FindNumber(targetNumber[i], brokenNum);
		}
	}

	return resultNumber;
}