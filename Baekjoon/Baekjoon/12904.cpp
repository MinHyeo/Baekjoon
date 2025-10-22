#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	while (s.size() != t.size()) {
		if (t[t.size() - 1] == 'B') {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		else {
			t.pop_back();
		}
	}

	int result = (t == s) ? 1 : 0;
	cout << result << "\n";

	return 0;
}