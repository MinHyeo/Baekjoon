#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

void Insert(Node*& node, int x) {
	if (node == NULL) {
		node = new Node();
		node->data = x;
		node->left = NULL;
		node->right = NULL;
	}
	else {
		if (node->data > x)
			Insert(node->left, x);
		else
			Insert(node->right, x);
	}
}

void Postorder(Node* node) {
	if (node == NULL)
		return;

	Postorder(node->left);
	Postorder(node->right);
	cout << node->data << "\n";
}

int main() {
	int x;
	Node* root = NULL;
	while (cin >> x) {
		Insert(root, x);
	}

	Postorder(root);

	return 0;
}