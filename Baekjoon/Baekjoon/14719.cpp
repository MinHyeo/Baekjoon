#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;

	vector<int> world(w);
	for (int i = 0; i < w; i++) {
		cin >> world[i];
	}

	int total = 0;
	for (int i = 1; i < w - 1; i++) {
		int max_left = *max_element(world.begin(), world.begin() + i);
		int max_right = *max_element(world.begin() + i + 1, world.end());

		int water = min(max_left, max_right) - world[i];
		if (water > 0)
			total += water;
	}

	cout << total << "\n";

	return 0;
}