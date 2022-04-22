#include<iostream>
using namespace std;

int max_triangle_path(int triangle[][5], int n);//dp求解
void trace_back(int triangle[][5], int** dp_back, int n);//构造并打印最优解

int main() {
	int triangle[5][5] = { { 7 }, { 3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 } };
	int res = max_triangle_path(triangle, 5);
	cout << "最大路径数字总和：" << res << endl;
	return 0;
}

int max_triangle_path(int triangle[][5], int n) {
	//初始化dp数组，dp_back数组用于回溯构建最优解
	int** dp = new int* [n + 1], ** dp_back = new int* [n + 1];
	for (int i = 0; i <= n; i++) { dp[i] = new int[n + 1]{}; dp_back[i] = new int [n + 1]{}; }
	//按顺序求解每个子问题最优解，最终求得原问题最优解
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (dp[i + 1][j] > dp[i + 1][j + 1]) {
				dp[i][j] = triangle[i][j] + dp[i + 1][j];
				dp_back[i][j] = 0;
			} else {
				dp[i][j] = triangle[i][j] + dp[i + 1][j + 1];
				dp_back[i][j] = 1;
			}
		}
	}

	trace_back(triangle, dp_back, n);
	int res = dp[0][0];
	for (int i = 0; i <= n; i++) { delete[]dp[i]; delete[]dp_back[i]; }
	delete[]dp; delete[]dp_back;
	return res;
}

void trace_back(int triangle[][5], int** dp_back, int n) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		cout << triangle[i][temp];
		if (i != n - 1)cout << "--";
		temp += dp_back[i][temp];
	}
	cout << endl;
}