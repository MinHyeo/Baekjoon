#include <iostream>
#include <queue>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	queue<pair<long long, int>> q;
	q.push({a, 1});

	while(!q.empty()) {
		pair<long long, int> num = q.front();
		q.pop();

		if (num.first == b) {
			cout << num.second << "\n";
			return 0;
		}

		if (num.first * 2 <= b) {
			q.push({ num.first * 2, num.second + 1 });
		}
		if (num.first * 10 + 1 <= b) {
			q.push({ num.first * 10 + 1, num.second + 1 });
		}
	}

	cout << -1 << "\n";

	return 0;
}