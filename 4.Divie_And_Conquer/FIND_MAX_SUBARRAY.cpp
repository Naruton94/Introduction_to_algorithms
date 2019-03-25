#include <vector>
#include <iostream>
using namespace std;
vector<int> FIND_MAX_CROSSING_SUBARRAY(vector<int> &A, int low, int mid, int high) {
	int left_sum = INT_MIN;
	int sum = 0;
	int max_left = 0;
	vector<int> ans(3);
	for (int i = mid; i >= low; --i) {
		sum = sum + A[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = INT_MIN;
	sum = 0;
	int max_right = 0;
	for (int j = mid + 1; j <= high; ++j) {
		sum = sum + A[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	return { max_left, max_right, (left_sum + right_sum) };
}
vector<int> FIND_MAXIMUM_SUBARRAY(vector<int> &A, int low, int high) {
	if (high == low)
		return { low, high, A[low] };
	int mid = (low + high) / 2;
	vector<int> ans_l = FIND_MAXIMUM_SUBARRAY(A, low, mid);
	vector<int> ans_r = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high);
	vector<int> ans_cross = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high);
	int left_sum = ans_l[2];
	int right_sum = ans_r[2];
	int cross_sum = ans_cross[2];
	if (left_sum >= right_sum && left_sum >= cross_sum)
		return ans_l;
	else if (right_sum >= left_sum && right_sum >= cross_sum)
		return ans_r;
	else
		return ans_cross;

	
}

int main(void) {
	vector<int> input({ 2,4,-7,5,2,-1,2,-4,3 });
	vector<int> ans = FIND_MAXIMUM_SUBARRAY(input, 0, 8);
	for (const auto i : ans) {
		cout << i << endl;
	}


}