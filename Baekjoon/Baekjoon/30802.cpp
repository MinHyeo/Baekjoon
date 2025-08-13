#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int size[6];
	for (int i = 0; i < 6; i++) {
		cin >> size[i];
	}

	int bundleOfTshirt, bundleOfPen;
	cin >> bundleOfTshirt >> bundleOfPen;

	int countTshirt = 0;
	for (int i = 0; i < 6; i++) {
		countTshirt += (size[i] / bundleOfTshirt);
		if (size[i] % bundleOfTshirt > 0) countTshirt++;
	}
	int bundleOfPenCount = 0, onePenCount = 0;
	bundleOfPenCount = n / bundleOfPen;
	onePenCount = n % bundleOfPen;

	cout << countTshirt << "\n";
	cout << bundleOfPenCount << " " << onePenCount << "\n";

	return 0;
}