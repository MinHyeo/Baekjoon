#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	if (m <= n) {
		if (m <= 2) {
			cout << "NEWBIE!" << "\n";
		}
		else {
			cout << "OLDBIE!" << "\n";
		}
	}
	else {
		cout << "TLE!" << "\n";
	}

	return 0;
}