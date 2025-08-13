#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	vector<int> v1, v2;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;;
		v1.push_back(num);
	}

	cin >> m;
	for (int j = 0; j < m; j++) {
		int num;
		cin >> num;;
		v2.push_back(num);
	}

	sort(v1.begin(), v1.end());
	
	for (int i = 0; i < m; i++) {
		int result = 0;
		if (binary_search(v1.begin(), v1.end(), v2[i])) {
			result = 1;
		}

		cout << result << "\n";
	}

	return 0;
}