#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, w, l;
	cin >> n >> w >> l;

	queue<int> buses;
	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		buses.push(weight);
	}

	int result, hap = 0;
	// pair<무게, 이동거리>
	queue<pair<int, int>> q;
	for (result = 0; true; result++) {
		if (q.empty() && buses.empty())
			break;
		//cout << "count : " << result << "\n";

		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			auto front = q.front(); q.pop();
			if (front.second >= w) {
				//cout << "이동 완료 : " << front.first << "\n";
				hap -= front.first;
			}
			else {
				//cout << "차량 이동 : " << front.first << ", " << front.second + 1 << "\n";
				q.push({ front.first, front.second + 1 });
			}
		}

		if (!buses.empty() && hap + buses.front() <= l && q.size() + 1 <= w) {
			q.push({ buses.front(), 1 });
			hap += buses.front();
			//cout << "차량 진입 : " << buses.front() << "\n";
			buses.pop();
		}
	}
	cout << result << "\n";

	return 0;
}