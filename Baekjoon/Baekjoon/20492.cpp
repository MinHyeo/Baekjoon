#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int case1 = (int)(n * 0.78);
	int case2 = (int)((n * 0.8) + (n * 0.2 * 0.78));

	cout << case1 << " " << case2 << "\n";

	return 0;
}