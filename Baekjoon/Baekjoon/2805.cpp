#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> trees;
int result;

void BinarySearch(int start, int end) {
	if (start > end) 
		return;

	int mid_height = (start + end) / 2;
	long long len = 0;
	for(int tree : trees){
		len += (tree - mid_height > 0) ? tree - mid_height : 0;
	}

	if (len >= m)
		result = max(result, mid_height);

	if (len >= m) {
		BinarySearch(mid_height + 1, end);
	}
	else {
		BinarySearch(start, mid_height - 1);
	}
}

int main() {
	cin >> n >> m;

	trees = vector<int>(n);
	int max_height = 0;
	result = 0;
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		max_height = max(trees[i], max_height);
	}

	BinarySearch(0, max_height);
	cout << result << "\n";

	return 0;
}