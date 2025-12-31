#include <iostream>
#include <vector>
using namespace std;

struct Node{
	Node* next_node[10];
	bool is_end = false;
	
};

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		bool result = true;
		Node* tree = new Node();

		for (int i = 0; i < n; i++) {
			string numbers;
			cin >> numbers;

			Node* node = tree;
			for (char number : numbers) {
				int index = -1;
				if (node->next_node[number - '0'] == nullptr) {
					node->next_node[number - '0'] = new Node();
				}
				node = node->next_node[number - '0'];

				if (node->is_end)
					result = false;
			}

			for (int j = 0; j < 10; j++) {
				if (node->next_node[j] != nullptr)
					result = false;
			}
			node->is_end = true;
		}

		if (result)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}