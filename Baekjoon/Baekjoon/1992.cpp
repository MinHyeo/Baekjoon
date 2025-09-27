#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> image;

bool IsVaild(int n, int x, int y){
	int base_number = image[y][x];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (base_number != image[y + i][x + j]) {
				return false;
			}
		}
	}
	return true;
}


void DnC(int n, int x, int y) {
	if (IsVaild(n, x, y)) {
		cout << image[y][x];
	}
	else {
		int new_n = n / 2;
		cout << "(";
		DnC(new_n, x, y);
		DnC(new_n, x + new_n, y);
		DnC(new_n, x, y + new_n);
		DnC(new_n, x + new_n, y + new_n);
		cout << ")";
	}
}

int main() {
	int n;
	cin >> n;

	image = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < n; j++) {
			image[i][j] = line[j] - '0';
		}
	}

	DnC(n, 0, 0);

	return 0;
}