#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int k;
		cin >> k;
		priority_queue<int> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;
		map<int, int> count;

		for (int j = 0; j < k; j++) {
			char commend;
			int num;
			cin >> commend >> num;

			switch (commend) {
			case 'I':
				maxHeap.push(num);
				minHeap.push(num);
				count[num]++;
				break;
			case 'D':
				if (num == 1) {
					if (!maxHeap.empty()) {
						count[maxHeap.top()]--;
						maxHeap.pop();
					}
				}
				else {
					if (!minHeap.empty()) {
						count[minHeap.top()]--;
						minHeap.pop();
					}
				}

				while (!maxHeap.empty() && count[maxHeap.top()] == 0)
					maxHeap.pop();
				while (!minHeap.empty() && count[minHeap.top()] == 0)
					minHeap.pop();
				break;
			}
		}

		if (maxHeap.empty() || minHeap.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << maxHeap.top() << " " << minHeap.top() << "\n";
		}
	}

	return 0;
}