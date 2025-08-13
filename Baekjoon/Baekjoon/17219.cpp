#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, string> data;
	for (int i = 0; i < n; i++) {
		string site, psw;
		cin >> site >> psw;

		data.insert({ site, psw });
	}

	for (int i = 0; i < m; i++) {
		string site;
		cin >> site;

		cout << data[site] << "\n";
	}

	return 0;
}