#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;

void BackTracking(int start, int depth) {
	if (depth == m) {
		for (int i = 0; i < depth; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i <= n; i++) {
		v.push_back(i);
		BackTracking(i, depth + 1);
		v.pop_back();
	}
}


int main() {
	cin >> n >> m;

	BackTracking(1, 0);

	return 0;
}