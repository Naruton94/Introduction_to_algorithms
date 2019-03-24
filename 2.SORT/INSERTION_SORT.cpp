#include <iostream>
#include <vector>
using namespace std;
template<class T>
void INSERTION_SORT(vector<T>& A) {
	T n = A.size();
	for (int j = 1; j < n; ++j) {
		T key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}

}

int main(void) {
	vector<double> a({ 3.0, 4.2, 89.5, 45.333, 23.125, 133.221, 2, 9.888, 0, 83.564654 });
	INSERTION_SORT(a);

	for (auto i : a) {
		cout << i << endl;
	}

#if 0
	int v;
	cin >> v;
	for (int i = 0; i < a.size();) {
		if (a[i] < v) {
			++i;
		}
		else if (a[i] == v) {
			cout << "Find it" << endl;
			break;
		}
		else {
			v = 0;
			cout << "Cannot find v" << endl;
			break;
			
		}
	}

#endif

	return 0;
}