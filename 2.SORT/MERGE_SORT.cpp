#include <iostream>
#include <vector>

using namespace std;
void MERGE(vector<int>& A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> L(n1 + 1), R(n2 + 1);
	for (int i = 0; i < n1; ++i) {
		L[i] = A[p + i];
	}
	for (int j = 0; j < n2; ++j) {
		R[j] = A[q + j + 1];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0, j = 0;
	for (int k = p; k <= r; ++k) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			++j;
		}
	}
}
void MERGE_SORT(vector<int>& A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q + 1, r);
		MERGE(A, p, q, r);
	}
}

int main(void) {
	vector<int> A({ 54, 6354,89741635,21,8979,18754,96854, 321 });
	MERGE_SORT(A, 0, 7);
	for (const auto i : A) {
		cout << i << endl;
	}
}