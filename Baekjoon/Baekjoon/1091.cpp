#include <iostream>
#include <vector>
using namespace std;

bool IsVaild(int n, vector<int> current_card, vector<int> p) {
	for (int i = 0; i < n; i++) {
		if (p[current_card[i]] != i % 3)
			return false;
	}
	return true;
}

bool IsPossible(int n, vector<int> current_card) {
	for (int i = 0; i < n; i++) {
		if (current_card[i] != i)
			return true;
	}
	return false;
}

int main() {
	int n;
	cin >> n;

	vector<int> p(n), s(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	// 현재 카드 위치 초기화
	vector<int> current_card(n);
	for (int i = 0; i < n; i++) {
		current_card[i] = i;
	}

	int result = 0;
	vector<int> next_card(n);
	// 카드 순서 맞는지 체크 후 카드 섞기
	while (!IsVaild(n, current_card, p)) {
		// 카드 섞기
		for (int i = 0; i < n; i++) {
			next_card[s[i]] = current_card[i];
		}
		current_card = next_card;
		result++;

		if (!IsPossible(n, current_card)) {
			cout << -1 << "\n";
			return 0;
		}
	}
	
	cout << result << "\n";

	return 0;
}