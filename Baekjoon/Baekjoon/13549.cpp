#include <iostream>
#include <deque>
#include <algorithm>
#include <climits>
using namespace std;

int checkPoint[200001];

int main() {
	int n, k;
	cin >> n >> k;

	fill(checkPoint, checkPoint + 200001, INT_MAX);
	deque<int> dq;

	if (n == k) {
		cout << 0 << "\n";

		return 0;
	}

	dq.push_front(n);
	checkPoint[n] = 0;
	while (!dq.empty()) {
		int point = dq.front();
		dq.pop_front();

		int next = point * 2;
		if ((next >= 0 && next <= 200000) && checkPoint[next] > checkPoint[point]) {
			checkPoint[next] = checkPoint[point];
			dq.push_front(next);
		}

		for (int next : {point + 1, point - 1}) {
			if ((next >= 0 && next <= 200000) && checkPoint[next] > checkPoint[point] + 1) {
				checkPoint[next] = checkPoint[point] + 1;
				dq.push_back(next);
			}			
		}
	}

	cout << checkPoint[k] << "\n";

	return 0;
}