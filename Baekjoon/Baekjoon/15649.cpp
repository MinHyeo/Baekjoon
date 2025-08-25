#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void BackTrarking(int start, int depth) {
	if (depth == m) {
		for (int num : v) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i <= n; i++) {
		if (find(v.begin(), v.end(), i) != v.end())
			continue;

		v.push_back(i);
		BackTrarking(1, depth + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;

	BackTrarking(1, 0);

	return 0;
}