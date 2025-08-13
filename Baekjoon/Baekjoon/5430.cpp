#include <iostream>
#include <string>
#include <vector>
#include<deque>
#include <sstream>
using namespace std;

deque<string> split(string input, char delimiter) {
	deque<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string funs;
		cin >> funs;

		int n;
		cin >> n;

		string numbers;
		deque<string> d;
		cin >> numbers;
		if (n > 0) {
			numbers = numbers.substr(1, numbers.size() - 2);
			 d = split(numbers, ',');
		}
		

		int dir = 1;
		bool isError = false;

		for (char fun : funs) {
			if (fun == 'R') {
				dir *= -1;
			}
			else {
				if (d.empty()) {
					isError = true;
					cout << "error" << "\n";
					break;
				}
				if (dir == 1) {
					d.pop_front();
				}
				else {
					d.pop_back();
				}
			}
		}

		if (!isError) {
			cout << "[";
			int j = (dir == -1) ? d.size() : 0;
			for (; !d.empty(); j + dir) {
				if (dir == 1) {
					cout << d.front();
					d.pop_front();
				}
				else {
					cout << d.back();
					d.pop_back();
				}
				if (!d.empty()) {
					cout << ",";
				}
			}
			cout << "]" << "\n";
		}
	}

	return 0;
}