#include <iostream>
using namespace std;

void hanoi(int n, int from, int tmp, int to) {
	if (n == 1) {
		cout << from << " " << to << endl;
	}
	else {
		hanoi(n - 1, from, to, tmp);
		cout << from << " " << to << endl;
		hanoi(n - 1, tmp, from, to);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << int(pow(2, n)) - 1 << endl;
	hanoi(n, 1, 2, 3);

	return 0;
}