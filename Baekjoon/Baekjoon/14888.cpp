#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> numbers;
vector<char> calcs;
long long maxResult = LLONG_MIN, minResult = INT_MAX;
long long result = 0;

vector<char> order;
vector<bool> isUse;

void BackTrarking(int start, int depth) {
	if (depth == n - 1) {
		result = numbers[0];
		for (int i = 0; i < n - 1; i++) {
			switch (order[i]) {
			case '+':
				result += numbers[i + 1];
				break;
			case '-':
				result -= numbers[i + 1];
				break;
			case '*':
				result *= numbers[i + 1];
				break;
			case '/':
				result /= numbers[i + 1];
				break;
			}
		}

		minResult = min(minResult, result);
		maxResult = max(maxResult, result);
		result = 0;

		return;
	}

	for (int i = start; i < n - 1; i++) {
		if (isUse[i])
			continue;

		order.push_back(calcs[i]);
		isUse[i] = true;
		BackTrarking(0, depth + 1);
		order.pop_back();
		isUse[i] = false;
	}
}

int main() {
	cin >> n;

	numbers = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			switch (i)
			{
			case 0:
				calcs.push_back('+');
				break;
			case 1:
				calcs.push_back('-');
				break;
			case 2:
				calcs.push_back('*');
				break;
			case 3:
				calcs.push_back('/');
				break;
			default:
				break;
			}
		}
	}
	isUse = vector<bool>(n - 1, false);

	BackTrarking(0, 0);
	cout << maxResult << "\n";
	cout << minResult << "\n";

	return 0;
}