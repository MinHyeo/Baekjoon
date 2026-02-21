#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	map<string, int> books;
	string title;
	for (int i = 0; i < n; i++) {
		cin >> title;
		books[title]++;
	}

	string max_title = "";
	int max_count = 0;
	for (auto book : books) {
		if (book.second > max_count) {
			max_title = book.first;
			max_count = book.second;
		}
	}
	cout << max_title << "\n";

	return 0;
}