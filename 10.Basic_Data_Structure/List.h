#include <iostream>
using namespace std;

class Node {
public:
	Node() {
		next = 0;
		prev = 0;
	}
	Node(int& el, Node *n = 0, Node *p = 0) {
		info = el;
		next = n;
		prev = p;
	}
	int info;
	Node* next;
	Node* prev;
};

class List {
public:
	List() {
		head = 0;
		tail = 0;
	}
	bool isEmpty();
	void insert_back(int &);
	void insert_front(int &);
	int pop_back();
	void printL();
	void deleteInfo(int );
	Node* search(int );
protected:
	Node *head, *tail;
};
void List::insert_back(int &el) {
	if (tail != 0) {
		tail = new Node(el, 0, tail);
		tail->prev->next = tail;
	}
	else {
		head = tail = new Node(el);
	}
}

int List::pop_back() {
	int el = tail->info;
	if (head == tail) {
		delete head;
		head = tail = 0;
	}
	else {
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
	}
	return el;
}
void List::printL() {
	Node* tmp = new Node;
	tmp = head;
	while (tmp != 0) {
		cout << tmp->info << "  ";
		tmp = tmp->next;
	}
	cout << endl;
}
void List::insert_front(int& el) {
	if (head != 0) {
		head->prev = new Node(el);
		head->prev->next = head;
		head = head->prev;
	}
	else {
		head = tail = new Node(el);
	}
}
bool List::isEmpty() {
	if (head == 0 && tail == 0)
		return true;
	else
		return false;
}
Node* List::search(int el) {
	if (!isEmpty()) {
		Node* tmp = head;
		tmp = head;
		while (tmp != 0) {
			if (tmp->info == el)
				return tmp;
			else
				tmp = tmp->next;
		}
		return nullptr;
	}
}
void List::deleteInfo(int el) {
	if (isEmpty())
		return;
	Node *tmp = search(el);
	if (tmp == nullptr) {
		cout << "Not fount " << el << endl;
		return;
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	delete tmp;
}
