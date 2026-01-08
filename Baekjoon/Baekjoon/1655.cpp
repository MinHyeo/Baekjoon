#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, less<int>> pq;
	priority_queue<int, vector<int>, greater<int>> greate_pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (pq.empty() || pq.top() >= num) {
			pq.push(num);
		}
		else {
			greate_pq.push(num);
		}

		int size = pq.size() + greate_pq.size();
		int less_size = (size / 2) + (size % 2);
		if (less_size > pq.size()) {
			pq.push(greate_pq.top());
			greate_pq.pop();
		}
		else if (less_size < pq.size()) {
			greate_pq.push(pq.top());
			pq.pop();

		}

		cout << pq.top() << "\n";
	}

	return 0;
}