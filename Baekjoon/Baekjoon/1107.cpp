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

//1. + / -버튼으로만 이동이 가능한가 ?
//2. target number 보다 큰 / 작은 숫자를 입력해야하는지 판단
//3. 

//번호 크기 구하는 함수
int GetDigitCount(int number);
//+/-버튼으로만 이동이 가능한지 판단
bool DecideOnlyButton(int targetNum);
//숫자의 자릿 수 분해
template <typename T>
vector<T> GetDigits(T number);
//목표 채널 값에 고장난 버튼이 있는지 확인
bool *CheckTargetNumber(int targetNum, int brokenNum[]);

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
		bool* brokenNumberPosition = CheckTargetNumber(targetNum, brokenNum);

	}

	return 0;
}

///<summary> 숫자의 자릿수를 구하는 함수 </summary>
int GetDigitCount(int number) {
	if (number == 0) return 1;
	return static_cast<int>(log10(abs(number)) + 1);
}
/// <summary>+/-버튼으로만 이동이 가능한지 판단</summary>
bool DecideOnlyButton(int targetNum) {
	int numLen = GetDigitCount(targetNum);
	int subNum = abs(targetNum - CURRENTNUMBER);

	if (subNum <= numLen)
		return true;
	
	return false;
}
///<summary>숫자의 자릿 수 분해</summary>
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
/// <summary>목표 채널에 고장난 버튼의 숫자가 존재하는지 체크</summary>
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
