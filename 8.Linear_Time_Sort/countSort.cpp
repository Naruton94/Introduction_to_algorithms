#include <iostream>
#include <vector>
using namespace std;
void CountSort(vector<int> &A, vector<int> &B, int k) {
	vector<int> C(k + 1, 0);
	for (int j = 0; j < A.size(); ++j) {
		C[A[j]] = C[A[j]] + 1;
	}
	for (int i = 1; i <= k; ++i) {
		C[i] = C[i] + C[i - 1];
	}
	for (int j = A.size() - 1; j >= 0; --j) {
		B[C[A[j]] - 1] = A[j];
		C[A[j]] -= 1;
	}
}

int main(void) {

}