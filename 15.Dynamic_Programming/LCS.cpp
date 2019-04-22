#include <iostream>
#include <vector>

using namespace std;

void LCS_Length(vector<int> x, vector<int> y, vector<vector<int>>& b, vector<vector<int>>& c) {
	int m = x.size();
	int n = y.size();
	for (int i = 0; i <= m; ++i) {
		c[i][0] = 0;
	}
	for (int j = 0; j <= n; ++j) {
		c[0][j] = 0;
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (x[i] == y[j]) {
				c[i + 1][j + 1] = c[i][j] + 1;
				b[i + 1][j + 1] = 0;
			}
			else if (c[i][j + 1] >= c[i + 1][j]) {
				c[i + 1][j + 1] = c[i][j + 1];
				b[i + 1][j + 1] = 1;
			}
			else {
				c[i + 1][j + 1] = c[i + 1][j];
				b[i + 1][j + 1] = 2;
			}
		}
	}
}

void printLCS(vector<vector<int>> c, vector<int> x, int i, int j) {
	if (i == 0 || j == 0) {
		return;
	}
	if (c[i][j] == c[i-1][j-1] + 1) {
		printLCS(c, x, i - 1, j - 1);
		cout << x[i - 1] << endl;
	}
	else if (c[i][j + 1] >= c[i + 1][j]) {
		printLCS(c, x, i - 1, j);
	}
	else
		printLCS(c, x, i, j - 1);
}

int main(void) {
	vector<int> x({1, 2, 3, 2, 4, 1, 2});
	vector<int> y({2, 4, 3, 1, 2, 1});
	int m = x.size();
	int n = y.size();
	vector<vector<int>> b(m + 1, vector<int>(n + 1));
	vector<vector<int>> c(m + 1, vector<int>(n + 1));
	LCS_Length(x, y, b, c);
	printLCS(c, x, m, n);

}