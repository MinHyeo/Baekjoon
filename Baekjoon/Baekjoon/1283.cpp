#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<bool> is_used(26, false);
	cin.ignore();

	while(n--) {
		string s;
		getline(cin, s);

		bool is_end = false;
		for (int i = 0; i < s.length(); i++) {
			if (i == 0 || s[i - 1] == ' ') {
				char c = tolower(s[i]);
				if (!is_used[c - 'a']) {
					is_end = true;
					is_used[c - 'a'] = true;

					s.insert(i + 1, "]");
					s.insert(i, "[");
					break;
				}
			}
		}

		if (!is_end) {
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == ' ')
					continue;

				char c = tolower(s[i]);
				if (!is_used[c - 'a']) {
					is_used[c - 'a'] = true;
					s.insert(i + 1, "]");
					s.insert(i, "[");
					break;
				}
			}
		}

		cout << s << "\n";
	}

	return 0;
}