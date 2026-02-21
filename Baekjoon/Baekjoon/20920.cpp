#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int>& b) {
	if (a.second != b.second)
		return a.second > b.second;

	if (a.first.length() != b.first.length())
		return a.first.length() > b.first.length();

	return a.first < b.first;
}

int main() {
	int n, m;
	cin >> n >> m;

	map<string, int> words;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;

		if(word.length() >= m)
			words[word]++;
	}
	vector<pair<string, int>> vec(words.begin(), words.end());
	sort(vec.begin(), vec.end(), compare);

	for (auto p : vec) {
		cout << p.first << "\n";
	}

	return 0;
}