#include<iostream>
using namespace std;

void arrange(int n, int depth, int* R);

int main() {
	int n, * R;
	cout << "���������鳤��n��"; cin >> n;
	R = new int[n];
	cout << "����������ÿ��Ԫ�أ�";
	for (int i = 0; i < n; i++) {
		cin >> R[i];
	}
	arrange(n, 0, R);
	delete[]R;
	return 0;
}

void arrange(int n, int depth, int* R) {//depth����ݹ�������
	if (n == depth) {//�����鳤����ݹ���������ȣ������������
		for (int i = n; i > 0; --i) {
			cout << *(R - i) << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < n - depth; i++) {
			if (i > 0 && R[0] == R[i])	continue;//�����ظ����
			swap(R[0], R[i]);
			arrange(n, depth + 1, R + 1);
			swap(R[0], R[i]);
		}
	}
}