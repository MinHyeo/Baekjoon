#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		vector<int> tree(n + 1, 0);
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			tree[b] = a;
		}

		int x, y;
		cin >> x >> y;

		vector<bool> is_visited(n + 1, false);
		int current = x;
		while (tree[current] != 0) {
			is_visited[current] = true;
			current = tree[current];
		}
		is_visited[current] = true;

		current = y;
		while (1) {
			if (is_visited[current]) {
				cout << current << "\n";
				break;
			}
			current = tree[current];
		}
	}

	return 0;
}