//Binary Search Tree
#include <iostream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* left, * right;
};

class BST {
private:
	Node* root;
	Node* insert(int, Node*);
	int getSize(Node*);
	void displayInOrder(Node*);

public:
	BST();
	void load(int, int, int);
	void insert(int);
	void insertNonRecursive(int);
	void displayInOrder();
	int getSize();
	Node* find(int);
};

//helper functions
Node* BST::insert(int v, Node* r) {
	if (r == nullptr) {
		r = new Node;
		r->left = r->right = nullptr;
		r->data = v;
	}
	else if (v < r->data) {
		r->left = insert(v, r->left);
	}
	else {
		r->right = insert(v, r->right);
	}
	return r;
}

void BST::displayInOrder(Node* r) {
	if (r != nullptr)
	{
		displayInOrder(r->left);
		cout << r->data << endl;
		displayInOrder(r->right);
	}
}

int BST::getSize(Node* r) {
	if (r == nullptr)
		return 0;
	else
		return 1 + getSize(r->left) + getSize(r->right);
}

//constructors
BST::BST() {
	root = nullptr;
}

void BST::load(int count, int min, int max) {
	for (int i = 0; i < count; i++) {
		insert(rand() % (max - min) + min);
	}
}


//setters
void BST::insert(int v) {
	root = insert(v, root);
}

void BST::insertNonRecursive(int v) {
	Node* prev = nullptr;
	Node* r = root;
	while (r != nullptr) {
		prev = r;
		if (v < r->data) {
			r = r->left;
			prev->left = r;
		}
		else {
			r = r->right;
			prev->right = r;
		}
	}
	r = new Node;
	r->data = v;
	r->left = r->right = nullptr;
}

//getters
int BST::getSize() {
	return getSize(root);
}

Node* BST::find(int v) {

}

//utility
void BST::displayInOrder() {
	displayInOrder(root);
}

int main() {
	BST bst1 = BST();
	cout << "Size: " << bst1.getSize() << endl << endl;

	bst1.insert(20);
	bst1.displayInOrder();
	cout << "Size: " << bst1.getSize() << endl << endl;

	bst1.insert(10);
	bst1.insert(30);
	bst1.displayInOrder();
	cout << "Size: " << bst1.getSize() << endl << endl;

	bst1.insert(5);
	bst1.insert(40);
	bst1.insert(25);
	bst1.displayInOrder();
	cout << "Size: " << bst1.getSize() << endl << endl;

	bst1.insert(0);
	bst1.insert(2);
	bst1.insert(-5);
	bst1.insert(-2);
	bst1.displayInOrder();
	cout << "Size: " << bst1.getSize() << endl << endl;
}

