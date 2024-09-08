#include <iostream>
#include <cmath>

#pragma region 상수값
#define BROKENBUTTON 10
#define CURRENTNUMBER 100
#pragma endregion

using namespace std;

//1. + / -버튼으로만 이동이 가능한가 ?
//2. target number 보다 큰 / 작은 숫자를 입력해야하는지 판단
//3.

//번호 크기 구하는 함수
int GetDigitCount(int number);
//+/-버튼으로만 이동이 가능한지 판단
bool DecideOnlyButton(int targetNum);

int main() {
	int result = 0;
	int targetNum;
	int brokenCount; 
	int brokenNum[BROKENBUTTON];

	cin >> targetNum;
	cin >> brokenCount;

	//부서진 숫자버튼
	for (int index = 0; index < brokenCount; index++) {
		cin >> brokenNum[index];
	}

	// +/-버튼으로만 이동이 가능한지 판단
	if (DecideOnlyButton(targetNum)) {
		cout << abs(targetNum - CURRENTNUMBER) << endl;
	}
	else {
		//이동하려고 하는 채널보다 큰/작은 숫자를 입력해야하는지 판단

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