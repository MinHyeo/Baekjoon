#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, score, p;
	cin >> n >> score >> p;

	vector<int> scores(n);
	for (int i = 0; i < n; i++) {
		cin >> scores[i];
	}

	if (n == 0) {
		cout << 1 << "\n";
		return 0;
	}
	if (n == p && score <= scores[n - 1]) {
		cout << -1 << "\n";
		return 0;
	}

	int rank = 1;
	for (int i = 0; i < n; i++) {
		if (score >= scores[i]) {
			rank = i + 1;
			break;
		}
		rank++;
	}
	cout << rank << "\n";

	return 0;
}