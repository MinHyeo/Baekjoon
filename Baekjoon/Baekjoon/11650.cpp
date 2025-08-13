#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int numbers[100000][2];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i][0] >> numbers[i][1];
	}

	//sort(numbers, numbers + n);

	for (int i = 0; i < n; i++) {
		cout << numbers[i][0] << " " << numbers[i][1] << endl;
	}

	return 0;
}