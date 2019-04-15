#include "E:\Code\Introduction_to_algorithms\12.Binary_Tree\BinarySearchTree.h"
#include <iostream>
using namespace std;
int main(void) {
	BinaryTree<int> t;

	for (int i = 1; i < 15; ++i) {
		t.insert(i);
	}
	


	t.inorderWalk();
	cout << "------------------------------" << endl;
	t.remove(1);
	t.inorderWalk();




}