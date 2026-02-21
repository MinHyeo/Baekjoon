#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> inputs;
	int max_input = 0;
	while(true) {
		int n;
		cin >> n;

		if (n == 0)
			break;
		inputs.push_back(n);
		max_input = max(max_input, n);
	}

	vector<bool> is_prime(max_input * 2 + 1, true);
	is_prime[1] = false;
	for (int i = 2; i <= 2 * max_input; i++) {
		for (int j = 2; i * j <= 2 * max_input; j++) {
			is_prime[i * j] = false;
		}
	}

	for (int n : inputs) {
		int result = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (is_prime[i])
				result += 1;
		}
		cout << result << "\n";
	}

	return 0;
}