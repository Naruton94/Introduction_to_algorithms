#include <iostream>
#include <vector>
const int K = 4;
using namespace std;

void insertion_sort1(vector<int> &A) {
	int n = A.size();
	for (int j = 1; j < n; ++j) {
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}
void insertion_sort2(vector<int> &A, int p, int r) {
	int n = r - p + 1;
	for (int j = p; j <= r; ++j) {
		int key = A[j];
		int i = j - 1;
		while (i >= p && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}
void merge(vector<int> &A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> L(n1 + 1);
	vector<int> R(n2 + 1);
	for (int i = 0; i < n1; ++i) {
		L[i] = A[p + i];
	}
	for (int i = 0; i < n2; ++i) {
		R[i] = A[q + i + 1];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0, j = 0;
	for (int k = p; k <= r; ++k) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			++i;
		}
		else {
			A[k] = R[j];
			++j;
		}
	}
}

void merge_sort1(vector<int> &A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort1(A, p, q);
		merge_sort1(A, q + 1, r);
		merge(A, p, q, r);
	}
}
void merge_sort2(vector<int> &A, int p, int r) {
	if (r - p <= K) {
		insertion_sort2(A, p, r);
	}
	else if (r - p > K) {
		int q = (p + r) / 2;
		merge_sort2(A, p, q);
		merge_sort2(A, q + 1, r);
		merge(A, p, q, r);
	}
}



int main(void) {
	const int n = 16;
	vector<int> A({23, 45, 1, 9, 456, 21, 7987, 121, 7874, 465, 254, 13216, 487, 7542, 78, 321, 1});
	/*
	for (int i = 0; i <= n; ++i) {
		A.push_back(rand());
	}
	*/
	
	merge_sort2(A, 0, A.size() - 1);
	for (const auto i : A) {
		cout << i << endl;
	}
	cout << endl;
	return 0;
}