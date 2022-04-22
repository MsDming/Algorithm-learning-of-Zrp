#include<iostream>
using namespace std;

int max_triangle_path(int triangle[][5], int n);//dp���
void trace_back(int triangle[][5], int** dp_back, int n);//���첢��ӡ���Ž�

int main() {
	int triangle[5][5] = { { 7 }, { 3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 } };
	int res = max_triangle_path(triangle, 5);
	cout << "���·�������ܺͣ�" << res << endl;
	return 0;
}

int max_triangle_path(int triangle[][5], int n) {
	//��ʼ��dp���飬dp_back�������ڻ��ݹ������Ž�
	int** dp = new int* [n + 1], ** dp_back = new int* [n + 1];
	for (int i = 0; i <= n; i++) { dp[i] = new int[n + 1]{}; dp_back[i] = new int [n + 1]{}; }
	//��˳�����ÿ�����������Ž⣬�������ԭ�������Ž�
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