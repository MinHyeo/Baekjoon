#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int min_pack = 1e9;
	int min_piece = 1e9;
	for (int i = 0; i < m; i++) {
		int pack, piece;
		cin >> pack >> piece;

		min_pack = min(min_pack, pack);
		min_piece = min(min_piece, piece);
	}

	int result = 1e9;
	result = min(result, min_pack * (n / 6) + min(min_pack, min_piece * (n % 6)));
	result = min(result, min_pack * ((n / 6) + 1));
	result = min(result, min_piece * n);

	cout << result << "\n";

	return 0;
}