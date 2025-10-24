#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;
	vector<int> count(100001, 0);
	vector<int> prev(100001, 0);

	// 처음부터 둘이 만나면 답 출력
	if (n == k) {
		cout << 0 << "\n";
		cout << n << "\n";

		return 0;
	}

	q.push(n);

	// BFS 시작
	while (!q.empty()) {
		int point = q.front(); q.pop();

		// 만나는 경우 나가기
		if (point == k) {
			break;
		}

		// 걷기 및 순간이동
		for (int next : { point + 1, point - 1, point * 2 }) {
			if (next <= 100000 && next >= 0 && !count[next]) {
				q.push(next);
				count[next] = count[point] + 1;
				prev[next] = point;
			}
		}
	}

	// 정답 출력
	cout << count[k] << "\n";
	vector<int> points;
	points.push_back(k);
	while(points.back() != n) {
		points.push_back(prev[points.back()]);
	}

	for (int i = points.size() - 1; i >= 0; i--) {
		cout << points[i] << " ";
	}
	cout << "\n";

	return 0;
}