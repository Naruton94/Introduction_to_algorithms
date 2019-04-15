#include <iostream>
using namespace std;

template <typename T>
struct BinaryNode{
	T element;
	BinaryNode *left = nullptr;
	BinaryNode *right = nullptr;
	BinaryNode *p = nullptr;
	BinaryNode() = default;
};
template <typename T>
class BinaryTree {
public:
	BinaryTree() = default;
	// ~BinaryTree();
	void insert(T k);
	void inorderWalk();
	void preorderWalk();
	void postorderWalk();
	bool search(T k);
	void remove(T k);
	T predecessor(T k);
	T successor(T k);
	T minimum();
	T maximum();
	int size() {
		return TreeSize;
	}


private:
	BinaryNode<T>* root = nullptr;
	BinaryNode<T>* search(BinaryNode<T> *x, T k);
	BinaryNode<T>* iterativeSearch(BinaryNode<T> *x, T k);
	BinaryNode<T>* minimum(BinaryNode<T> *x);
	BinaryNode<T>* maximum(BinaryNode<T> *x);
	BinaryNode<T>* successor(BinaryNode<T> *x);
	BinaryNode<T>* predecessor(BinaryNode<T> *x);
	void inorderWalk(BinaryNode<T> *x);
	void preorderWalk(BinaryNode<T> *x);
	void postorderWalk(BinaryNode<T> *x);
	void insert(BinaryNode<T>* z);
	void transplant(BinaryNode<T>* u, BinaryNode<T>* v);
	void remove(BinaryNode<T>* z);
	int TreeSize = 0;
};


template <typename T>
BinaryNode<T>* BinaryTree<T>::search(BinaryNode<T> *x, T k) {
	if (x == nullptr || k == x->element) {
		return x;
	}
	if (k < x->element) {
		return search(x->left, k);
	}
	else
		return search(x->right, k);
}

template <typename T>
BinaryNode<T>* BinaryTree<T>::iterativeSearch(BinaryNode<T> *x, T k) {
	while (x != nullptr && k != x->element) {
		if (k < x->element)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

template <typename T>
BinaryNode<T>* BinaryTree<T>::minimum(BinaryNode<T> *x) {
	while (x->left != nullptr)
		x = x->left;
	return x;
}
template <typename T>
BinaryNode<T>* BinaryTree<T>::maximum(BinaryNode<T> *x) {
	while (x->right != nullptr)
		x = x->right;
	return x;
}
template <typename T>
BinaryNode<T>* BinaryTree<T>::successor(BinaryNode<T> *x) {
	if (x->right != nullptr)
		return minimum(x->right);
	auto y = x->p;
	while (y != nullptr && x == y->right) {
		x = y;
		y = y->p;
	}
	return y;
}
template <typename T>
BinaryNode<T>* BinaryTree<T>::predecessor(BinaryNode<T> *x) {
	if (x->left != nullptr)
		return maximum(x->left);
	auto y = x->p;
	while (y != nullptr && x == y->left) {
		x = y;
		y = y->p;
	}
	return y;
}

template <typename T>
void BinaryTree<T>::insert(BinaryNode<T>* z) {
	BinaryNode<T>* y = nullptr;
	BinaryNode<T>* x = root;
	while (x != nullptr) {
		y = x;
		if (z->element < x->element) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	z->p = y;
	if (y == nullptr) {
		root = z;
	}
	else if (z->element < y->element) {
		y->left = z;
	}
	else
		y->right = z;

	TreeSize++;
}

template <typename T>
void BinaryTree<T>::inorderWalk(BinaryNode<T>* x) {
	if (x != nullptr) {
		inorderWalk(x->left);
		cout << x->element << endl;
		inorderWalk(x->right);
	}
}
template <typename T>
void BinaryTree<T>::preorderWalk(BinaryNode<T>* x) {
	if (x != nullptr) {
		cout << x->element << endl;
		preorderWalk(x->left);
		preorderWalk(x->right);
	}
}
template <typename T>
void BinaryTree<T>::postorderWalk(BinaryNode<T>* x) {
	if (x != nullptr) {
		postorderWalk(x->left);
		postorderWalk(x->right);
		cout << x->element << endl;
	}
}

template <typename T>
bool BinaryTree<T>::search(T k) {
	if (search(root, k) == nullptr)
		return false;
	else
		return true;
}
template <typename T>
void BinaryTree<T>::insert(T k) {
	BinaryNode<T>* tmp = new BinaryNode<T>;
	tmp->element = k;
	insert(tmp);
}
template <typename T>
void BinaryTree<T>::postorderWalk() {
	postorderWalk(root);
}
template <typename T>
void BinaryTree<T>::inorderWalk() {
	inorderWalk(root);
}
template <typename T>
void BinaryTree<T>::preorderWalk() {
	preorderWalk(root);
}

template <typename T>
T BinaryTree<T>::predecessor(T k) {
	BinaryNode<T>* tmp = new BinaryNode<T>;
	tmp = search(root, k);
	if (tmp == nullptr)
		return tmp;
	tmp = predecessor(tmp);
	return tmp->element;
}

template <typename T>
T BinaryTree<T>::successor(T k) {
	BinaryNode<T>* tmp = search(root, k);
	if (tmp == nullptr)
		return tmp;
	tmp = successor(tmp);
	return tmp->element;
}

template <typename T>
T BinaryTree<T>::maximum() {
	return maximum(root)->element;
}

template <typename T>
T BinaryTree<T>::minimum() {
	return minimum(root)->element;
}
template <typename T>
void BinaryTree<T>::transplant(BinaryNode<T>* u, BinaryNode<T>* v) {
	// 用以 v 为根的子树代替以 u 为根的子树
	if (u->p == nullptr) {
		// 如果 u 是 root
		root = v;
	}
	else if(u == u->p->left) {
		// 如果 u 是左孩子
		u->p->left = v;
	}
	else {
		// 如果 u 是右孩子
		u->p->right = v;
	}
	if (v != nullptr)
		v->p = u->p;
}
template <typename T>
void BinaryTree<T>::remove(BinaryNode<T>* z) {
	if (z == nullptr)
		return;
	if (z->left == nullptr) {
		transplant(z, z->right);
	}
	else if (z->right == nullptr) {
		transplant(z, z->left);
	}
	else {
		BinaryNode<T>* y = minimum(z->right);
		// y 是 z 的后继节点
		if (y->p != z) {
			// 如果 y 不是 z 的孩子节点
			transplant(y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->p = y;
	}
	TreeSize--;
}
template <typename T>
void BinaryTree<T>::remove(T k) {
	BinaryNode<T>* tmp = search(root, k);
	if (tmp != nullptr)
		remove(tmp);
}