#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bucketSort(vector<double> &A) {
	int n = A.size();
	vector<vector<double>> B(n);
	for (int i = 0; i < n; ++i) {
		int index = static_cast<int> (n * A[i]);
		B[index].push_back(A[i]);
	}
	vector<double> C;
	for (int i = 0; i < n; ++i) {
		if (!B[i].empty()) {
			sort(B[i].begin(), B[i].end());
			C.insert(C.end(), B[i].begin(), B[i].end());
		}
	}
	A = C;
}

int main(void) {
	vector<double> data({ 0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68 });
	bucketSort(data);
	for (auto i : data) {
		cout << i << endl;
	}
}