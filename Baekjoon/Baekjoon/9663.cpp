#include <iostream>
#include <vector>
using namespace std;

int n, result = 0;
vector<int> board;
vector<bool> isUsed;

void BackTracking(int start, int depth) {
	if (depth == n) {
		result++;
		return;
	}

	for (int i = 0; i < n; i++) {
		//다른 퀜을 죽이는지 체크
		if (isUsed[i])
			continue;
		
		bool isChecked = false;
		for (int j = 1; depth - j >= 0; j++) {
			if (board[depth - j] == i - j) {
				isChecked = true;
				break;
			}
			if (board[depth - j] == i + j) {
				isChecked = true;
				break;
			}
		}
		if (isChecked)
			continue;

		//보드에 입력
		board.push_back(i);
		isUsed[i] = true;
		//다른 퀜 체크
		BackTracking(0, depth + 1);
		//보드에서 빼기
		board.pop_back();
		isUsed[i] = false;
	}
}

int main() {
	cin >> n;
	isUsed = vector<bool>(n, false);

	BackTracking(0, 0);

	cout << result << "\n";
	return 0;
}