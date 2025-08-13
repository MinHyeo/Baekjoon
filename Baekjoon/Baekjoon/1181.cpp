#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string a, const string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}

int main() {
	vector<string> arr;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		arr.push_back(str);
	}

	sort(arr.begin(), arr.end(), compare);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}

	return 0;
}