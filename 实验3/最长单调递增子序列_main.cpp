#include<iostream>
#include<algorithm>
using namespace std;

int MaxSubNum(int n, int* s);

int main() {
	int a[6] = { 4, 5, 7, 1, 3, 9 };
	int b[9] = { 1, 4, 3, 2, 6, 5, 7, 0, 9 };
	cout << "a数组的最长单调递增子序列数目为：" << MaxSubNum(6, a) << endl;
	cout << "b数组的最长单调递增子序列数目为：" << MaxSubNum(9, b) << endl;
	return 0;
}

int MaxSubNum(int n, int* a) {
	int* dp = new int[n];
	for (int i = 0; i < n; i++)dp[i] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}
	int res = *max_element(dp, dp + n);
	delete[] dp;
	return res;
}