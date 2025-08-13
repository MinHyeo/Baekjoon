#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int k;
	cin >> k;

	for (int i = 1; i <= k; i++) {
		int n;
		cin >> n;
		vector<int> score(n);
		
		int totalScore = 0, maxScore = 0, minScore = 100;
		for (int j = 0; j < n; j++) {
			cin >> score[j];
			totalScore += score[j];
			maxScore = max(score[j], maxScore);
			minScore = min(score[j], minScore);
		}

		cout << "Class " << i << "\n";
		cout << "Max " << maxScore << ", Min " << minScore << ", Largest gap " << totalScore / n << "\n";
	}

	return 0;
}
