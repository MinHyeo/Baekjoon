#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		int num;
		cin >> num;
		pq.push(num);
	}

	int result = 0;
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		int sum = a + b;
		result += sum;
		pq.push(sum);
	}
	cout << result << "\n";

	return 0;
}