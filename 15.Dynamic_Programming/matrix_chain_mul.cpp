#include <iostream>
#include <vector>
using namespace std;
void matrix_chain_order(vector<int> p) {
	int n = p.size() - 1;
	vector<vector<int>> m(n + 1, vector<int>(n + 1));
	vector<vector<int>> s(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i) {
		m[i][i] = 0;
	}
	for (int l = 2; l <= n; ++l) {
		for (int i = 1; i <= n - l + 1; ++i) {
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; ++k) {
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}



int main(void) {
	return 0;
}