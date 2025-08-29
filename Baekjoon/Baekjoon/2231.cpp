#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int num = i;
		int sum = num;
		
		while (num != 0) {
			sum += (num % 10);
			num /= 10;
		}

		if (sum == n) {
			cout << i << "\n";
			return 0;
		}
	}

	cout << "0" << "\n";
	return 0;
}