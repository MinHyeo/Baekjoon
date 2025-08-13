#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map <int, string> pocketmons_int;
	unordered_map <string, int> pocketmons_str;
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;

		pocketmons_int.insert({ i, name });
		pocketmons_str.insert({ name, i });
	}

	for (int i = 0; i < m; i++) {
		string commend;
		cin >> commend;

		if (atoi(commend.c_str()) == 0) {
			cout << pocketmons_str[commend] << "\n";
		}
		else {
			cout << pocketmons_int[stoi(commend)] << "\n";
		}
	}

	return 0;
}