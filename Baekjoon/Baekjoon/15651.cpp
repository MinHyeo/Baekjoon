#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> result;

void BackTracking(int start, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		result.push_back(i);
		BackTracking(1, depth + 1);
		result.pop_back();
	}
}

int main() {
	cin >> n >> m;

	BackTracking(1, 0);

	return 0;
}