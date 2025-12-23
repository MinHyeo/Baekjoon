#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	int hap = 0;
	int index = 1;
	while(x > index) {
		x -= index;
		index++;
	}
	index++;

	int a = 0, b = 0;
	if (index % 2 == 0) {
		a = index - x;
		b = x;
	}
	else {
		a = x;
		b = index - x;
	}

	cout << a << "/" << b << "\n";

	return 0;
}