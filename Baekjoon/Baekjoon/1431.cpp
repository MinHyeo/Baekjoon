#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SumString(const string& a) {
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		if (isdigit(a[i])) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool cmp(const string &a, const string &b) {
	if (a.size() != b.size())
		return a.size() < b.size();

	int sumA = SumString(a);
	int sumB = SumString(b);
	if (sumA != sumB) {
		return sumA < sumB;
	}

	return a < b;
}

int main() {
	int n;
	cin >> n;

	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s.begin(), s.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << s[i] << "\n";
	}

	return 0;
}