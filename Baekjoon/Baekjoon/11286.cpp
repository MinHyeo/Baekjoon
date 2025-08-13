#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, cmp> pq;
	while (n--) {
		int x;
		cin >> x;

		switch (x) {
		case 0:
			if (pq.empty())
				cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
			break;
		default:
			pq.push(x);
		}
	}

	return 0;
}