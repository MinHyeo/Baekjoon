#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long a = 1, b = 1, c = 0;
	for (int i = 3; i <= n; i++) {
		c = (a + b) % 1000000007;
		a = b;
		b = c;
	}

	long long result1 = (n <= 2) ? 1 : b;
	int result2 = n - 2;

	cout << result1 << " " << result2 << "\n";

	return 0;
}