# 1. AVL tree 연습

```c++

#include <iostream>
#include <queue>
#include<algorithm>
#include<vector>
using namespace std;

struct node {
	int value;
	node* left;
	node* right;
	int height;
};

class AVLtree {
public:
	int search(int idx, node* n);
	int getHeight(node* n);
	void setHeight(node* n);
	node* left_rotate(node* n);
	node* right_rotate(node* n);
	node* balance(node* n);
	node* insert(node* n, int idx);
	node* remove(node* n, int idx);
	node* left_most(node* n);
private:
	node* root;
	node ptr;
};


int main() {

	int n, f, k,cmd;
	cin >> n >> f >> k;

	for (int i = 0; i < k; i++) {
		cin >> cmd;
	}

}

int AVLtree::search(int idx, node* n) {
	int v = n->value;
	if (v > idx) {
		return search(idx, n->left);
	}
	else if (v < idx) {
		return search(idx, n->right);
	}
	else if (v == idx) {
		return v;
	}
}

int AVLtree::getHeight(node* n) {
	if (n == NULL) {
		return -1;
	}
	return n->height;
}

void AVLtree::setHeight(node* n) {
	n->height = max(getHeight(n->right), getHeight(n->left)) + 1;
}

node* AVLtree::left_rotate(node* n) {
	node* A = n->right;
	node* B = A->left;

	A->left = n;
	n->right = B;

	setHeight(n);
	setHeight(B);

	return A;
}

node* AVLtree::right_rotate(node* n) {
	node* A = n->left;
	node* B = A->right;

	A->right = n;
	n->left = B;

	setHeight(n);
	setHeight(B);

	return A;
}
node* AVLtree::balance(node* n) {
	static int balancing_factor = 1;
	int hl = getHeight(n->left), hr = getHeight(n->right);

	if (hl > hr + balancing_factor) {
		node* l = n->left;
		int hll = getHeight(l->left), hlr = getHeight(l->right);
		if (hll < hlr) {
			n->left = left_rotate(n->left);
		}
		return right_rotate(n);
	}
	else if (hr > hl + balancing_factor) {
		node* r = n->right;
		int hrl = getHeight(r->left), hrr = getHeight(r->right);
		if (hrl > hrr) {
			n->right = right_rotate(n->right);
		}
		return left_rotate(n);
	}
	else {
		return n;
	}
}

node* AVLtree::insert(node* n, int idx) {

	if (n == NULL) {
		node* newNode = new node;
		newNode->value = idx;
		newNode->height = 0;
		newNode->left = NULL;
		newNode->right = NULL;

		return newNode;
	}

	if (idx < n->value)
		n->left = insert(n->left, idx);
	else if (n->value < idx)
		n->right = insert(n->right, idx);
	else
		return n;

	setHeight(n);

	return balance(n);
}

node* AVLtree::remove(node* n, int idx) {
	if (n == NULL)
		return NULL;

	if (idx < n->value)
		n->left = remove(n->left, idx);
	else if (n->value < idx)
		n->right = remove(n->right, idx);
	else {
		node* l = n->left;
		node* r = n->right;
		if (l == NULL || r == NULL) {
			if (l == NULL)
				n = r;
			else
				n = l;
		}
		else {
			node* very_next = left_most(r);
			n->value = very_next->value;
			n->right = remove(r, very_next->value);
		}
	}

	if (n == NULL)
		return NULL;

	setHeight(n);

	return balance(n);
}

node* AVLtree::left_most(node* n) {
	node* cur= n;
	while (cur->left != NULL) {
		cur = cur->left;
	}

	return cur;
}

```