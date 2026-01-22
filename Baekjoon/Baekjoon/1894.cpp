#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << fixed << setprecision(3);
	double x1, y1, x2, y2, x3, y3, x4, y4;

	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
		double common_x, common_y, end1_x, end1_y, end2_x, end2_y;

		if (x1 == x3 && y1 == y3) {
			common_x = x1;
			common_y = y1;
			end1_x = x2;
			end1_y = y2;
			end2_x = x4;
			end2_y = y4;
		}
		else if (x1 == x4 && y1 == y4) {
			common_x = x1;
			common_y = y1;
			end1_x = x2;
			end1_y = y2;
			end2_x = x3;
			end2_y = y3;
		}
		else if (x2 == x3 && y2 == y3) {
			common_x = x2;
			common_y = y2;
			end1_x = x1;
			end1_y = y1;
			end2_x = x4;
			end2_y = y4;
		}
		else {
			common_x = x2;
			common_y = y2;
			end1_x = x1;
			end1_y = y1;
			end2_x = x3;
			end2_y = y3;
		}

		double res_x = end1_x + end2_x - common_x;
		double res_y = end1_y + end2_y - common_y;

		cout << res_x << " " << res_y << "\n";
	}
	return 0;
}