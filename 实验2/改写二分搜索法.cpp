#include<iostream>
using namespace std;

template<class T>//ʹ��ģ��
void binary_search(T* a, T target, int n, int& i, int& j);

int main() {
	int a[10] = { 12,45,57,78,82,89,95,98,113,125 }, target, i = -1, j = -1;
	cout << "������Ҫ���ҵ����֣�";
	while (cin >> target) {
		binary_search(a, target, 10, i, j);
		cout << "i=" << i << endl << "j=" << j << endl;
		cout << "������Ҫ��ѯ�����֣�";
	}
		
	return 0;
}

template<class T>
void binary_search(T* a, T target, int n, int& i, int& j) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == target) {//���ҳɹ�
			i = j = mid;
			cout << "���ҳɹ���" << endl;
			return;
		}
		else if (a[mid] < target) {//Ŀ��Ԫ�����Ұ���
			low = mid + 1;
		}
		else {//Ŀ��Ԫ���������
			high = mid - 1;
		}
	}
	i = high; j = low;//����ʧ�ܣ�����i��j����ֵ
	cout << "����ʧ��" << endl;
}