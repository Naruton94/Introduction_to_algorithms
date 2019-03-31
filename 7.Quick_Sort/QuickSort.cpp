#include <iostream>
#include <vector>

using namespace std;
int partition(vector<int> &A, int p, int r);
void QuickSort(vector<int>& A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int partition(vector<int> &A, int p, int r) {
	int i = p - 1;
	int x = A[r];
	for (int j = p; j < r; ++j) {
		if (A[j] < x) {
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

int main(){
	vector<int> A({ 2, 8, 7, 1, 3, 5, 6, 4 });
	QuickSort(A, 0, A.size() - 1);
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << endl;
	}
	return 0;
}