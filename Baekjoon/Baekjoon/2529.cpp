#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k;
vector<char> inequalitys;
vector<bool> isUsed;
string max_result;
string min_result;

bool IsCheck(char a, char b, char inequality) {
	if (inequality == '<') {
		if (a > b) return false;
	}
	if (inequality == '>') {
		if (a < b) return false;
	}

	return true;
}

void BackTracking_Max(int depth, string s) {
	if (!max_result.empty()) {
		return;
	}

	if (depth == k + 1) {
		max_result = s;
		return;
	}

	for (int i = 9; i >= 0; i--) {
		if (!isUsed[i] && (depth == 0 || IsCheck(s[depth - 1], i + '0', inequalitys[depth - 1]))) {
			isUsed[i] = true;
			BackTracking_Max(depth + 1, s + to_string(i));
			isUsed[i] = false;
		}
	}
}

void BackTracking_Min(int depth, string s) {
	if (!min_result.empty()) {
		return;
	}

	if (depth == k + 1) {
		min_result = s;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (!isUsed[i] && (depth == 0 || IsCheck(s[depth - 1], i + '0', inequalitys[depth - 1]))) {
			isUsed[i] = true;
			BackTracking_Min(depth + 1, s + to_string(i));
			isUsed[i] = false;
		}
	}
}

int main() {
	cin >> k;

	inequalitys = vector<char>(k);
	for (int i = 0; i < k; i++) {
		cin >> inequalitys[i];
	}

	isUsed = vector<bool>(10, false);
	BackTracking_Max(0, "");
	isUsed = vector<bool>(10, false);
	BackTracking_Min(0, "");

	cout << max_result << "\n";
	cout << min_result << "\n";

	return 0;
}