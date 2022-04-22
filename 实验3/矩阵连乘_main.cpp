#include<iostream>
#include<vector>
#define MAXNUM 2147483647
using namespace std;
//���ټ������
int min_calculate(vector<vector<int>> A, vector<vector<int>>& m, vector<vector<int>>& s);
//�������Ž�
void trace_back(vector<vector<int>>& s, int i, int j);

int main() {
	vector<vector<int>> A = {
		{30,35},
		{35,15},
		{15,5},
		{5,10},
		{10,20},
		{20,25}
	};
	vector<vector<int>> m;//����m��Ϊdp����
	vector<vector<int>> s;//����s���ڹ������Ž�
	vector<int>temp(A.size() + 1);
	m.resize(A.size() + 1, temp);
	s.resize(A.size() + 1, temp);
	cout << "���ټ��������";
	cout << min_calculate(A, m, s) << endl;
	cout << "���ż������";
	trace_back(s, 1, 6);
	return 0;
}

int min_calculate(vector<vector<int>> A, vector<vector<int>>& m, vector<vector<int>>& s) {
	int n = A.size();
	for (int i = 1; i <= n; i++) {//��ʼ��m����
		m[i][i] = 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			int max_temp = MAXNUM;
			for (int k = j; k < j + i; k++) {
				if (m[j][k] + m[k + 1][j + i] + A[j - 1][0] * A[k - 1][1] * A[j + i - 1][1] < max_temp) {
					max_temp = m[j][k] + m[k + 1][j + i] + A[j - 1][0] * A[k - 1][1] * A[j + i - 1][1];
					s[j][j + i] = k;
				}
			}
			m[j][j + i] = max_temp;
		}
	}
	return m[1][n];
}

void trace_back(vector<vector<int>>& s, int i, int j) {
	if (i == j) {
		cout << "A" << i;
	}
	else {//�ݹ�������Ž�
		cout << "(";
		trace_back(s, i, s[i][j]);
		trace_back(s, s[i][j] + 1, j);
		cout << ")";
	}
}