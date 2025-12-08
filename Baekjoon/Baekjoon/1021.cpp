#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	int result = 0;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;

		int index = 0;
		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == target) {
				index = j;
				break;
			}
		}

		if (index <= dq.size() / 2) {
			while (dq.front() != target) {
				dq.push_back(dq.front());
				dq.pop_front();
				result += 1;
			}
		}
		else {
			while (dq.front() != target) {
				dq.push_front(dq.back());
				dq.pop_back();
				result += 1;
			}
		}

		dq.pop_front();
	}

	cout << result << "\n";

	return 0;
}