/*
280
DoublyLinkedList 1
Gunnar Marquardt
*/
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next, * prev;
};

class DoublyLinkedList {
private:
	Node *top, *bottom;
	int size;
public:
	//constructors
	DoublyLinkedList();
	//setters
	void addNodeTop(int);
	void addNodeBottom(int);
	void deleteTop();
	void deleteBottom();
	void deleteAt(Node*);
	void insertBefore(Node*, int);
	void insertAfter(Node*, int);
	void set(Node*, int);
	//getters
	int getSize();
	Node* findFirst(int);
	Node* findLast(int);
	int howMany(int);
	int get(Node*);
	int getTop();
	int getBottom();
	Node* getTopNode();
	//utility
	void displayFromTop();
	void displayFromBottom();
};


DoublyLinkedList::DoublyLinkedList() {
	top = bottom = nullptr;
	size = 0;
} //O(1)

void DoublyLinkedList::addNodeTop(int v) {
	Node* p = new Node;
	p->data = v;
	p->next = top;
	p->prev = nullptr;
	if (size == 0)
		bottom = p;
	else
		top->prev = p;
	top = p;
	size++;
} //O(1)

void DoublyLinkedList::addNodeBottom(int v) {
	Node* p = new Node;
	p->data = v;
	p->prev = bottom;
	p->next = nullptr;
	if (size == 0)
		top = p;
	else
		bottom->next = p;
	bottom = p;
	size++;
} //O(1)

void DoublyLinkedList::deleteTop() {
	if (top != nullptr) {
		Node* temp = top;
		if (top == bottom)
			top = bottom = nullptr;
		else {
			top = top->next;
			top->prev = nullptr;
		}
		delete temp;
		size--;
	}
} //O(1)

void DoublyLinkedList::deleteBottom() {
	if (bottom != nullptr) {
		Node* temp = bottom;
		if (bottom == top)
			bottom = top = nullptr;
		else {
			bottom = bottom->prev;
			bottom->next = nullptr;
		}
		delete temp;
		size--;
	}
} //O(1)

void DoublyLinkedList::deleteAt(Node* p) {
	if (p == top)
		deleteTop();
	else if (p == bottom)
		deleteBottom();
	else {
		p->next->prev = p->prev;
		p->prev->next = p->next;
		delete p;
		size--;
	}
} //O(1)

void DoublyLinkedList::insertBefore(Node* p, int d) {
	Node* n = new Node;
	n->data = d;
	n->next = p;
	n->prev = p->prev;
	p->prev->next = n;
	p->prev = n;
	size++;
} //O(1)

void DoublyLinkedList::insertAfter(Node* p, int d) {
	Node* n = new Node;
	n->data = d;
	n->next = p->next;
	n->prev = p;
	p->next->prev = n;
	p->next = n;
	size++;
} //O(1)

void DoublyLinkedList::set(Node* p, int d) {
	if(p != nullptr)
		p->data = d;
} //O(1)

Node* DoublyLinkedList::findFirst(int d) {
	Node* runner = new Node;
	runner = top;
	while (runner != nullptr) {
		if (runner->data == d) {
			break;
		}
		runner = runner->next;
	}
	return runner;
} //O(n)

Node* DoublyLinkedList::findLast(int d) {
	Node* runner = new Node;
	runner = bottom;
	while (runner != nullptr) {
		if (runner->data == d) {
			break;
		}
		runner = runner->prev;
	}
	return runner;
} //O(n)

int DoublyLinkedList::howMany(int d) {
	Node* runner = new Node;
	int count = 0;
	runner = top;
	while (runner != nullptr) {
		if (runner->data == d) {
			count++;
		}
		runner = runner->next;
	}
	return count;
} //O(n)

int DoublyLinkedList::get(Node* p) {
	if (p != nullptr)
		return p->data;
	return INT_MAX;
} //O(1)

int DoublyLinkedList::getTop() {
	if (top != nullptr)
		return top->data;
	return INT_MAX;
} //O(1)

int DoublyLinkedList::getBottom() {
	if (bottom != nullptr)
		return bottom->data;
	return INT_MAX;
} //O(1)

Node* DoublyLinkedList::getTopNode() {
	return top;
} //O(1)

void DoublyLinkedList::displayFromTop() {
	Node* runner = top;
	while (runner != nullptr) {
		cout << runner->data << endl;
		runner = runner->next;
	}
} //O(n)

void DoublyLinkedList::displayFromBottom() {
	Node* runner = bottom;
	while (runner != nullptr) {
		cout << runner->data << endl;
		runner = runner->prev;
	}
} //O(n)

int DoublyLinkedList::getSize() {
	return size;
} //O(1)

int main() {
	DoublyLinkedList dl1 = DoublyLinkedList();

	dl1.addNodeTop(12);
	dl1.addNodeTop(50);
	dl1.addNodeTop(-88);
	dl1.addNodeBottom(-1);
	dl1.addNodeBottom(-2);
	dl1.addNodeBottom(-3);

	cout << "Display from top 1..." << endl;
	dl1.displayFromTop();
	cout << "Display from bottom 1..." << endl;
	dl1.displayFromBottom();
	cout << endl;

	dl1.deleteBottom();
	cout << "Display from top 2..." << endl;
	dl1.displayFromTop();
	cout << "Display from bottom 2..." << endl;
	dl1.displayFromBottom();
	cout << "Size: " << dl1.getSize() << endl << endl;

	Node* temp = dl1.getTopNode();
	Node* r = temp->next->next->next;
	dl1.deleteAt(r);
	cout << "Display from top 3..." << endl;
	dl1.displayFromTop();
	cout << "Display from bottom 3..." << endl;
	dl1.displayFromBottom();
	cout << "Size: " << dl1.getSize() << endl << endl;

	r = dl1.findFirst(12);
	cout << "Value found: " << r->data << endl << endl;

	dl1.insertAfter(r, 999);
	cout << "Display from top 4..." << endl;
	dl1.displayFromTop();
	cout << "Display from bottom 4..." << endl;
	dl1.displayFromBottom();
	cout << "Size: " << dl1.getSize() << endl << endl;
}