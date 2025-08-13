#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b){
		if (a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	}
};

int main() {
	int n;
	cin >> n;

	
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		pq.push({ x, y });
	}

	for (int i = 0; i < n; i++) {
		cout << pq.top().first << " " << pq.top().second << "\n";
		pq.pop();
	}

	return 0;
}