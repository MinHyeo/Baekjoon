#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> lines(n, 0);
	for (int i = 0; i < n; i++) {
		int order;
		cin >> order;

		int count = 0;
		for (int j = 0; j < n; j++) {
			if (lines[j] != 0)
				continue;

			if (count == order) {
				lines[j] = i + 1;
				break;
			}
			count++;
		}
	}

	for (int line : lines) {
		cout << line << " ";
	}
	cout << "\n";

	return 0;
}