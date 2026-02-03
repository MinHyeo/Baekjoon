#include <iostream>
using namespace std;

int Factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << Factorial(n) / (Factorial(k) * Factorial(n - k)) << "\n";

	return 0;
}