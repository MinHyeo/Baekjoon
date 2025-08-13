#include <iostream>
#include <vector>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int maxSize = a.size() > b.size() ? a.size() + 1 : b.size() + 1;
	vector<int> hap(maxSize, 0);

	for (int i = 0; i < maxSize; i++) {
		if (i < a.size())
			hap[i] += a[a.size() - i - 1] - '0';
		if (i < b.size())
			hap[i] += b[b.size() - i - 1] - '0';
		if(hap[i] >= 10){
			hap[i + 1] += hap[i] / 10;
			hap[i] %= 10;
		}
	}

	int index = hap.size() - 1;
	while(index > 0 && hap[index] == 0)
		index--;

	for (int i = index; i >= 0; i--) {
		cout << hap[i];
	}
	cout << "\n";

	return 0;
}