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
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	if (equal(A.begin(), A.end(), B.begin())) {
		cout << 1 << "\n";
		return 0;
	}
	for (int i = 1; i < n; i++) {
		int loc = i - 1;
		int newItem = A[i];

		while (0 <= loc && newItem < A[loc]) {
			A[loc + 1] = A[loc];

			if (A[loc + 1] == B[loc + 1]) {
				if (equal(A.begin(), A.end(), B.begin())) {
					cout << 1 << "\n";
					return 0;
				}
			}
			loc--;
		}
		if (loc + 1 != i) {
			A[loc + 1] = newItem;
			if (equal(A.begin(), A.end(), B.begin())) {
				cout << 1 << "\n";
				return 0;
			}
		}
	}

	cout << 0 << "\n";
	
	return 0;
}