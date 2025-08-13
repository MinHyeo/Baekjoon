#include<iostream>
#include <algorithm>
using namespace std;

#define MAX 26

int complex = 1;
int result[200] = { 0 };

void grassFire(int map[][MAX], int n, int i, int j) {
	if (map[i][j] == 1) {
		map[i][j] = complex;
		result[complex] += 1;
	}
	else return;

	if (i + 1 < n) {
		grassFire(map, n, i + 1, j);
	}
	if (i - 1 >= 0) {
		grassFire(map, n, i - 1, j);
	}
	if (j + 1 < n) {
		grassFire(map, n, i, j + 1);
	}
	if (j - 1 >= 0) {
		grassFire(map, n, i, j - 1);
	}
}

void Serching(int map[][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				complex += 1;
				grassFire(map, n, i, j);
			}
		}
	}
}

int main() {
	int map[MAX][MAX] = { 0 };
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < n; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	Serching(map, n);

	//결과 출력
	cout << complex - 1 << endl;
	sort(result, result + complex + 1);
	for (int i = 0; i < complex + 1; i++) {
		if (result[i] != 0) {
			cout << result[i] << endl;
		}
	}
}