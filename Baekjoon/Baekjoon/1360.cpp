#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, string>> texts;
	texts.push_back({ 0, "" });

	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;

		if (command == "type") {
			char c;
			int t;
			cin >> c >> t;

			string new_text = texts.back().second + c;
			texts.push_back({ t, new_text });
		}
		else {
			int b, t;
			cin >> b >> t;

			int back_time = t - b - 1;
			if (back_time < 0)
				back_time = 0;
			
			int index = 0;
			for (int j = texts.size() - 1; j >= 0; j--) {
				if (texts[j].first <= back_time) {
					index = j;
					break;
				}
			}
			texts.push_back({ t, texts[index].second });
		}
	}

	cout << texts.back().second << "\n";

	return 0;
}