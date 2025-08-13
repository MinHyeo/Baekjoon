#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	double area = 0;
	vector<double> x, y;
	int count;
	cin >> count;

	for (int i = 0; i < count; i++) {
		int a, b;
		cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}

	for (int i = 0; i < count; i++) {
		int j = (i + 1) % count;
		area += (x[i] * y[j]) - (x[j] * y[i]);
	}
	area = fabs(area) / 2;

	cout << fixed << setprecision(1) << area << "\n";

	return 0;
}