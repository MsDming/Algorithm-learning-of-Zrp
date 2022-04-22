#include<iostream>
using namespace std;

int min_sub_sum(int* a, int n, int m);
void traceBack(int** trace_back, int* a, int n, int m);

int main() {
	int a[5] = { 5, 4, 3, 2, 1 };
	int n = sizeof(a) / sizeof(a[0]), m = 3;
	int min_sum_res = min_sub_sum(a, n, m);
	cout << "���Ž�Ϊ��" << min_sum_res << endl;
	return 0;
}

int min_sub_sum(int* a, int n, int m) {
	int** dp = new int* [n + 1], ** trace_back = new int* [n + 1];
	//dp[i][j]��ʾn=i,m=j����Сm�κ�����Ľ�
	int maxt{}, temp{}, k{};
	for (int i = 0; i <= n; i++) { 
		dp[i] = new int[n + 1]{};
		trace_back[i] = new int[n + 1]{};
	}
	//��ʼ��dp��һ��
	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i - 1][1] + a[i - 1];
	}
	for (int j = 2; j <= m; j++) {
		for (int i = j; i <= n; i++) {
			for (k = 1, temp = INT_MAX; k < i; k++) {
				maxt = max(dp[i][1] - dp[k][1], dp[k][j - 1]);
				if (temp > maxt) {
					temp = maxt;
					trace_back[i][j] = k;
				}
			}
			dp[i][j] = temp;
		}
	}
	cout << "�ָ�����£�" << endl;
	traceBack(trace_back, a, n, m);
	int res = dp[n][m];
	for (int i = 0; i <= n; i++) {
		delete[]dp[i];
		delete[]trace_back[i];
	}delete[]dp; delete[]trace_back;
	return res;
}

void traceBack(int** trace_back, int* a, int n, int m) {
	if (m == 0)return;
	int sum{};
	//�ݹ�����ָ��
	traceBack(trace_back, a, trace_back[n][m], m - 1);
	for (int i = trace_back[n][m]; i < n; i++) {
		cout << a[i] << ' '; sum += a[i];
	}cout << '\t' << "�ö������кͣ�" << sum << endl;
}