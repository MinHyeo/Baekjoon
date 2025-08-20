#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		map<string, vector<string>> m;
		for(int i = 0;i < n;i++){
			string name, type;
			cin >> name >> type;
			m[type].push_back(name);
		}

		int result = 1;
		for (auto& a : m) {
			result *= (a.second.size() + 1);
		}

		cout << result - 1 << "\n";
	}

	return 0;
}