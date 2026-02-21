#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(nullptr);

	int n;
	cin >> n;

	while (n--) {
		int t;
		cin >> t;
		
		long long num;
		map<long long, int> map;
		for (int i = 0; i < t; i++) {
			cin >> num;
			map[num]++;
		}

		bool is_found = false;
		for (auto p : map) {
			if (p.second > t / 2) {
				cout << p.first << "\n";
				is_found = true;
				break;
			}
		}

		if (!is_found) {
			cout << "SYJKGW" << "\n";
		}
	}

	return 0;
}