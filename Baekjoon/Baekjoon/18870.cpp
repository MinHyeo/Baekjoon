#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> coordinate(n);
	vector<int> sorted(n);
	for (int i = 0; i < n; i++) {
		cin >> coordinate[i];
		sorted[i] = coordinate[i];
	}
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
	
	for (int i = 0; i < n; i++) {
		int index = lower_bound(sorted.begin(), sorted.end(), coordinate[i]) - sorted.begin();
		cout << index << " ";
	}
	cout << "\n";

	return 0;
}