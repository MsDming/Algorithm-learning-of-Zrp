#include<iostream>
using namespace std;

int half_set(int n);

int main() {
	int n;
	cout << "������n(0<n<200)��";
	cin >> n;
	cout << half_set(n);
	return 0;
}

int half_set(int n) {
	int res = 1;//��ʼԪ�ر�����һ��
	if (n > 1) {
		for (int i = 1; i <= n / 2; i++) {
			res += half_set(i);
			res--;//ȥ���ظ�Ԫ��
		}
		res += n / 2;
	}
	return res;
}