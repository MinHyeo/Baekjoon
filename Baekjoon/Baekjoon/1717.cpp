#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int Find(vector<int>& v, int a) {
	if (v[a] != a) {
		v[a] = Find(v, v[a]);
	}
	return v[a];
}

void Union(vector<int>& v, int a, int b) {
	a = Find(v, a);
	b = Find(v, b);

	if (a != b) {
		v[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1);
	iota(v.begin(), v.end(), 0);

	for (int i = 0; i < m; i++) {
		int c, a, b;
		cin >> c >> a >> b;

		if (c == 0) {
			Union(v, a, b);
		}
		else {
			int parentA = Find(v, a);
			int parentB = Find(v, b);
			if (parentA == parentB) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}

	return 0;
}