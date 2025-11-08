#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct cmp {
	bool operator()(string a, string b) {
		return a > b;
	}
};

int main() {
	string s;
	cin >> s;

	priority_queue<string, vector<string>, cmp> pq;
	while (s.length() > 0) {
		pq.push(s);
		s = s.substr(1);
	}

	while (!pq.empty()) {
		string result = pq.top();
		pq.pop();

		cout << result << "\n";
	}

	return 0;
}