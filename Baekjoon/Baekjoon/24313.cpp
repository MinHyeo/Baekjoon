#include <iostream>
#include <vector>
using namespace std;

int a1, a0, c, n0;

bool CheckResult() {
	return (a1 * n0 + a0 <= c * n0) && (c >= a1);
}

int main() {
	cin >> a1 >> a0;
	cin >> c >> n0;

	cout << CheckResult() << "\n";

	return 0;
}