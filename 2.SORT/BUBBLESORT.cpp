#include <iostream>
#include <vector>
using namespace std;
void BUBBLESORT(vector<int>& A) {
	for (int i = 0; i < A.size() - 1; ++i) {
		for (int j = A.size() - 1; j > i; --j) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
			}
		}
	}
}
int main(void) {
	vector<int> A({ 23, 45, 1, 9, 456, 21, 7987, 121, 7874, 465, 254, 13216, 487, 7542, 78, 321, 1 });
	vector<int> B = A;
	BUBBLESORT(A);
	for (const auto i : A) {
		cout << i << endl;
	}
}