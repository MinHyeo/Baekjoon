#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	int zero[41], one[41];
	zero[0] = 1;
	one[0] = 0;
	zero[1] = 0;
	one[1] = 1;


	for (int i = 2; i <= 40; i++) {
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << zero[n] << " " << one[n] << "\n";
	}

	return 0;
}