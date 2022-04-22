#include<iostream>
using namespace std;

int back_pack(int w[], int v[], int c, int n);//dp 0-1����
void trace_back(int** traceback, int i, int j, int* w);//������Ž�

int main() {
	int w[5] = { 2, 2, 4, 5, 4 };
	int v[5] = { 6, 3, 5, 4, 6 };
	int c = 10, n = sizeof(w) / sizeof(w[0]);
	int max_value = back_pack(w, v, c, n);
	cout << endl << "����ֵΪ��" << max_value << endl;
	return 0;
}

int back_pack(int w[], int v[], int c, int n) {
	//��ʼ��dp����
	int** dp = new int* [n + 1];
	for (int i = 0; i <= n; i++) { dp[i] = new int[c + 1]{}; }
	for (int i = 0; i <= n; i++) { dp[i][0] = 0; }
	for (int i = 0; i <= c; i++) { dp[0][i] = 0; }
	//traceback�������ڹ������Ž�
	int** traceback = new int* [n + 1];
	for (int i = 0; i <= n; i++) { traceback[i] = new int[c + 1]{}; }

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
			if (j >= w[i - 1]) {
				dp[i][j] = (dp[i - 1][j] > dp[i - 1][j - w[i - 1]] + v[i - 1]) ? 
					(dp[i - 1][j]) : (dp[i - 1][j - w[i - 1]] + v[i - 1]);
				traceback[i][j] = (dp[i - 1][j] > dp[i - 1][j - w[i - 1]] + v[i - 1]) ? 0 : 1;
			} else {
				dp[i][j] = dp[i - 1][j];
				traceback[i][j] = 0;
			}
		}
	}

	cout << "���Ž⣺" << endl;
	for (int i = 0; i < n; i++) { cout << "x" << i << '\t'; }cout << endl;
	trace_back(traceback, n, c, w);
	int res = dp[n][c];
	for (int i = 0; i <= n; i++) { 
		delete[]dp[i]; 
		delete[]traceback[i];
	}delete[]dp; delete[]traceback;
	return res;
}

void trace_back(int** traceback, int i, int j, int* w) {
	if (i < 1 || j < 1)return;
	if (traceback[i][j] == 1) {//�ݹ�������Ž�
		trace_back(traceback, i - 1, j - w[i - 1], w);
	} else {
		trace_back(traceback, i - 1, j, w);
	}
	cout << traceback[i][j] << '\t';
}