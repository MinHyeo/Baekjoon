#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	string s;
	cin >> s;

	string text = "I";
	for (int i = 0; i < n; i++) {
		text += "OI";
	}

	int count = 0;
	size_t pos = s.find(text, 0);
	while (pos != std::string::npos) {
		count++;
		pos = s.find(text, pos + 1);
	}
	cout << count << "\n";

	return 0;
}