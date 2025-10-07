#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int l;
	cin >> l;

	string s;
	cin >> s;

	long long hash_value = 0;
	long long r = 1;
	long long m = 1234567891;

	for (int i = 0; i < l; i++) {
		hash_value = (hash_value + (s[i] - 'a' + 1) * r) % m;
		r = (r * 31) % m;
	}
	cout << hash_value << "\n";
}