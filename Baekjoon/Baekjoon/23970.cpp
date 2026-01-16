#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int diffrent_count = 0;
	for (int i = 0; i < n; i++) {
		cin >> B[i];
		if (A[i] != B[i])
			diffrent_count++;
	}

	if (diffrent_count == 0) {
		cout << 1 << "\n";
		return 0;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			if (A[j] > A[j + 1]) {
				if (A[j] == B[j])
					diffrent_count++;
				if (A[j + 1] == B[j + 1])
					diffrent_count++;

				swap(A[j], A[j + 1]);

				if (A[j] == B[j])
					diffrent_count--;
				if (A[j + 1] == B[j + 1])
					diffrent_count--;

				if (diffrent_count == 0) {
					cout << 1 << "\n";
					return 0;
				}
			}				
		}
	}

	cout << 0 << "\n";

	return 0;
}