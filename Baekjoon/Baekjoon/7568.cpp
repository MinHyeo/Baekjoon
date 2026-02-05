#include <iostream>
#include <vector>
using namespace std;

struct Data {
	int weight;
	int height;
};

int main() {
	int n;
	cin >> n;

	vector<Data> v;
	for (int i = 0; i < n; i++) {
		int weight, height;
		cin >> weight >> height;
		v.push_back({ weight, height });
	}

	for (int i = 0; i < n; i++) {
		int rank = 1;
		for (int j = 0; j < n; j++) {
			if (v[i].height < v[j].height && v[i].weight < v[j].weight)
				rank++;
		}

		cout << rank << " ";
	}
	cout << "\n";

	return 0;
}