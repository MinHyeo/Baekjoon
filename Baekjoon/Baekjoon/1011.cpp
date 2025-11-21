#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		long long x, y;
		cin >> x >> y;

		long long distance = y - x;
		long long result = (long long)sqrt(4 * distance - 3);

		cout << result << "\n";
	}

	return 0;
}