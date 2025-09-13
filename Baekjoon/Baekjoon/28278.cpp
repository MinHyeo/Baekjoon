#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	stack<int>s;
	while (n--) {
		int command;
		cin >> command;

		switch (command) {
		case 1:
			int num;
			cin >> num;
			s.push(num);
			break;
		case 2:
			if (s.empty())
				cout << "-1" << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
			break;
		case 3:
			cout << s.size() << "\n";
			break;
		case 4:
			cout << (int)s.empty() << "\n";
			break;
		case 5:
			if (s.empty())
				cout << "-1" << "\n";
			else
				cout << s.top() << "\n";
			break;
		}
	}

	return 0;
}