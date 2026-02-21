#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int l;
	cin >> l;

	vector<int> numbers(l);
	for (int i = 0; i < l; i++) {
		cin >> numbers[i];
	}
	int n;
	cin >> n;
	
	sort(numbers.begin(), numbers.end());

	if (find(numbers.begin(), numbers.end(), n) != numbers.end()) {
		cout << 0 << "\n";
		return 0;
	}

	int left = 0, right = 1001;
	for (int num : numbers) {
		if (num < n)
			left = num;
		else {
			right = num;
			break;
		}
	}

	cout << (n - left) * (right - n) - 1;

	return 0;
}