#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
class Stack {
public:
	bool empty();
	bool push(int x);
	int pop();
private:
	vector<int> S;
	int top = 0;
};
bool Stack::empty() {
	if (top == 0)
		return true;
	else
		return false;
}
int Stack::pop() {
	if (top == 0) {
		cout << "Error! Stack is empty." << endl;
		return INT_MIN;
	}
	int tmp = S[top - 1];
	top--;
	S.pop_back();
	return tmp;
}
bool Stack::push(int x) {
	S.push_back(x);
	top++;
	return true;
}

class Queue {
public:
	bool empty();
	bool enQueue(int x);
	int deQueue();

private:
	vector<int> Q;
	int head = 0;
};
bool Queue::empty() {
	if (head == 0)
		return true;
	else
		return false;
}
bool Queue::enQueue(int x) {
	Q.push_back(x);
	head++;
	return true;
}
int Queue::deQueue() {
	if (head == 0) {
		cout << "Error! Queue is empty." << endl;
		return INT_MIN;
	}
	int tmp = Q[0];
	Q.erase(Q.begin());
	head--;
	return tmp;
}

