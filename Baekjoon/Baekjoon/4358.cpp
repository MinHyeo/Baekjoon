#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string s;
	map<string, int> words;
	int total_count = 0;

	while (getline(cin, s)) {
		words[s]++;
		total_count++;
	}

	cout << fixed;
	cout.precision(4);
	for (auto m : words) {
		double percent = (double)m.second / total_count * 100.0;
		cout << m.first << " " << percent << "\n";
	}

	return 0;
}