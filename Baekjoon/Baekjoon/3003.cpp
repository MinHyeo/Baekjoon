#include <iostream>
using namespace std;

int main() {
	int ches[] = { 1, 1, 2, 2, 2, 8 };
	int input[6];

	for (int i = 0; i < 6; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < 6; i++) {
		cout << ches[i] - input[i] << " ";
	}
	cout << "\n";

	return 0;
}