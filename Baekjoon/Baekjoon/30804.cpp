#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> tanghuru(n);
	for (int i = 0; i < n; i++) {
		cin >> tanghuru[i];
	}

	int kind = 0, type[10] = { 0 }, index = 0;
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (type[tanghuru[i]]++ == 0) {
			kind++;
		}

		while (kind > 2) {
			if (--type[tanghuru[index]] == 0) {
				kind--;
			}
			index++;
		}
		result = max(result, i - index + 1);
	}

	cout << result << "\n";

	return 0;
}