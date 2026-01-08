#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int result = 0;
	vector<bool> is_visited(b + 1, false);
	for (long long i = 2; i <= b; i++) {
		if (!is_visited[i]) {
			int index = 2;
			for (long long j = 2; i * j <= b; j++) {
				is_visited[i * j] = true;
				if (pow(i, index) == i * j) {
					//cout << "i : " << i << ", j : " << j << ", i * j : " << i * j << "\n";
					result++;
					index++;
				}
					
			}
		}
	}

	cout << result << "\n";

	return 0;
}