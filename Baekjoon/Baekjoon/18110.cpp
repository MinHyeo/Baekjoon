#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 0) {
		cout << "0" << "\n";
		return 0;
	}

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int exCount = round(n * 0.15);
	
	int sum = 0;
	for (int i = exCount; i < n - exCount; ++i) {
		sum += v[i];
	}

	cout << round((double)sum / (n - exCount * 2)) << "\n";

	return 0;
}