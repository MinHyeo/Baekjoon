#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	return a < b;
}

int main() {
	int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s.begin(), s.end(), cmp);

	int result = n;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bool is_same = true;;
			for (int k = 0; k < s[i].size(); k++) {
				if (s[i][k] != s[j][k]) {
					is_same = false;
					break;
				}
			}

			if (is_same) {
				result--;
				break;
			}
		}
	}

	cout << result << "\n";

	return 0;
}