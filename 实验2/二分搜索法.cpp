#include<iostream>
using namespace std;

template<class T>//����ʹ��ģ��
int binary_search(T* a, T target, int n);

int main() {
	int a[10] = { 12,45,57,78,82,89,95,98,113,125 }, target;
	cout << "������Ҫ���ҵ����֣�";
	while (cin >> target) {
		int res = binary_search(a, target, 10);
		if (res != -1) {
			cout << "���ҽ��Ϊ��" << res << endl;
		}
		cout << "������Ҫ���ҵ����֣�";
	}
	return 0;
}

template<class T>
int binary_search(T* a, T target, int n) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == target) {
			return mid;//�ҵ�Ŀ��Ԫ��
		}
		else if (a[mid] < target) {//Ŀ��Ԫ�����Ұ���
			low = mid + 1;
		}
		else {//Ŀ��Ԫ���������
			high = mid - 1;
		}
	}
	cout << "����ʧ��" << endl;
	return -1;
}