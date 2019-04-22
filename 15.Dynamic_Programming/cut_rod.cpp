#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cut_rod(vector<int> p, int n) {
	// µ›πÈ µœ÷
	if (n == 0)
		return 0;
	int q = INT_MIN;
	for (int i = 0; i < n; ++i) {
		q = max(q, p[i] + cut_rod(p, n - i - 1));
	}
	return q;
}



int memoized_cut_rod_aux(vector<int> p, int n, vector<int> r) {
	if (r[n] >= 0)
		return r[n];
	int q;
	if (n == 0)
		q = 0;
	else {
		q = INT_MIN;
		for (int i = 0; i < n; ++i)
			q = max(q, p[i] + memoized_cut_rod_aux(p, n - i - 1, r));
	}
	r[n] = q;
	return q;
}


int memoized_cut_rod(vector<int> p, int n) {
	vector<int> r(n + 1, INT_MIN);
	return memoized_cut_rod_aux(p, n, r);
}
int buttom_up_cut_rod(vector<int> p, int n) {
	vector<int> r(n + 1, INT_MIN);
	r[0] = 0;
	for (int j = 0; j < n; ++j) {
		int q = INT_MIN;
		for (int i = 0; i <= j; ++i) {
			q = max(q, p[i] + r[j - i]);
		}
		r[j + 1] = q;
	}
	return r[n];
}
void extended_bottom_up_cut_rod(vector<int> p, int n,  vector<int> &r, vector<int> &s) {
	r[0] = 0;
	for (int j = 0; j < n; ++j) {
		int q = INT_MIN;
		for (int i = 0; i <= j; ++i) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j + 1] = i + 1;
			}
			r[j + 1] = q;
		}
	}
}

int main(void) {
	vector<int> p({ 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 });
	int n = 10;
	vector<int> r(n + 1);
	vector<int> s(n + 1);
	extended_bottom_up_cut_rod(p, n, r, s);
	for (auto i : r) {
		cout << i << endl;
	}
	for (auto i : s) {
		cout << i << endl;
	}
}