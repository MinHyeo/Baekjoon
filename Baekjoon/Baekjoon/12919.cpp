#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool TransToS(string s, string t) {
	if (s.size() > t.size())
		return false;
	if (s == t)
		return true;

	bool is_possible = false;

	if (t.back() == 'A') {
		is_possible |= TransToS(s, t.substr(0, t.size() - 1));
	}

	if (t.front() == 'B') {
		string temp = t.substr(1, t.size());
		reverse(temp.begin(), temp.end());
		is_possible |= TransToS(s, temp);
	}

	return is_possible;
}

int main() {
	string s, t;
	cin >> s;
	cin >> t;

	cout << TransToS(s, t) ? 1 : 0;
	cout << "\n";
	
	return 0;
}