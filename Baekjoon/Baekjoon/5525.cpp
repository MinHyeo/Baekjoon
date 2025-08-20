#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	string s;
	cin >> s;

	int count = 0, k = 0;
	for (int i = 1; i < m - 1;) {
		if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
			k++;
			if (k >= n)
				count++;
			i += 2;
		}
		else {
			k = 0;
			i++;
		}
	}

	cout << count << "\n";

	return 0;
}