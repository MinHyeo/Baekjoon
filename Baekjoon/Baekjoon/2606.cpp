#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Computer {
	int index;
	vector<int> lines;
};

int main() {
	int computerCount, lineCount;
	cin >> computerCount;

	vector<Computer> computer;
	for (int i = 0; i < computerCount; i++) {
		Computer newComputer;
		newComputer.index = i;
		newComputer.lines = vector<int>();
		computer.push_back(newComputer);
	}

	cin >> lineCount;
	for (int i = 0; i < lineCount; i++) {
		int a, b;
		cin >> a >> b;

		computer[a - 1].lines.push_back(b - 1);
		computer[b - 1].lines.push_back(a - 1);
	}

	queue<int> q;
	vector<bool> isVaus(computerCount, false);
	isVaus[0] = true;
	for (int i = 0; i < computer[0].lines.size(); i++) {
		q.push(computer[0].lines[i]);
	}

	int count = 0;
	while (!q.empty()) {
		int num = q.front();
		q.pop();

		if (isVaus[num])
			continue;

		count++;
		isVaus[num] = true;

		for (int i = 0; i < computer[num].lines.size(); i++) {
			int comNum = computer[num].lines[i];
			if(!isVaus[comNum])
				q.push(computer[num].lines[i]);
		}
	}

	cout << count << "\n";
}