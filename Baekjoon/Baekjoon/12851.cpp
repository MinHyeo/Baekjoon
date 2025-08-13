#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int checkPoint[200001];
int countWay[200001];

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;

	if (n == k) {
		cout << 0 << "\n";
		cout << 1 << "\n";

		return 0;
	}

	q.push(n);
	checkPoint[n] = 1;
	countWay[n] = 1;
	while (!q.empty()) {
		int point = q.front();
		q.pop();

		for (int next : {point + 1, point - 1, point * 2}) {
			if (next < 0 || next > 200000) continue;

			if (checkPoint[next] == 0) {
				checkPoint[next] = checkPoint[point] + 1;
				countWay[next] = countWay[point];

				q.push(next);
			}
			else if(checkPoint[next] == checkPoint[point] + 1) {
				countWay[next] += countWay[point];
			}
		}
	}

	cout << checkPoint[k] - 1 << "\n";
	cout << countWay[k] << "\n";

	return 0;
}