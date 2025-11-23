#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r1, c1, r2, c2;

	cin >> n >> r1 >> c1 >> r2 >> c2;
	int size = n * 2 - 1;

	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			int new_i = i % size;
			int new_j = j % size;

			int alphabet_num = abs((n - 1) - new_i) + abs((n - 1) - new_j);
			if (alphabet_num < n)
				cout << (char)('a' + (alphabet_num % 26));
			else
				cout << '.';
		}
		cout << "\n";
	}

	return 0;
}