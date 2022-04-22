#include<iostream>
using namespace std;

void natural_merge_sort(int a[], int n);//��Ȼ�鲢����
void natural_merge_pass(int a[], int b[], int n, bool& sort);//һ�˹鲢
void natural_merge(int a[], int b[], int ptr_low, int ptr_middle, int ptr_high);//���������й鲢

int main() {
	int a[9] = { 0, -1, 9, 3, 4, 6, 2, 5, 7 };
	int b[9] = { 0, -1, 1, 3, 8, 4, 2, 5, 7 };
	int na = sizeof(a) / sizeof(a[0]), nb = sizeof(b) / sizeof(b[0]);
	natural_merge_sort(a, na);
	natural_merge_sort(b, nb);
	cout << "��Ȼ�ϲ�����" << endl;
	cout << "a������������";
	for (int i = 0; i < na; i++)cout << a[i] << " "; cout << endl;
	cout << "b������������";
	for (int i = 0; i < nb; i++)cout << b[i] << " "; cout << endl;
	return 0;
}

void natural_merge_sort(int a[], int n) {
	int* b = new int[n] {};
	bool sort = false;
	while (!sort) {
		natural_merge_pass(a, b, n, sort);
		natural_merge_pass(b, a, n, sort);
	}
	delete[]b;
}

void natural_merge_pass(int a[], int b[], int n, bool& sort) {
	int ptr_low = 0, ptr_middle = -1, ptr_high = -1;
	//lowָ��ǰһ����Ԫ�أ�middleָ��ǰһ��βԪ�أ�highָ���һ��βԪ��
	while (ptr_high < n - 1) {
		ptr_middle = ptr_low = ptr_high + 1;
		while (ptr_middle < n - 1 && a[ptr_middle] < a[ptr_middle + 1]) {
			ptr_middle++;
		}
		if (ptr_middle == n - 1) {
			if (ptr_low == 0) {//lowָ���һ��Ԫ����middleָ�����һ��Ԫ�أ�˵���Ѿ��ź���
				for (int i = 0; i < n; i++)b[i] = a[i];
				sort = true;
				return;
			}
			for (int i = ptr_low; i <= ptr_middle; i++) {
				b[i] = a[i];
			}
			return;
		}
		else {
			ptr_high = ptr_middle + 1;
			while (ptr_high < n - 1 && a[ptr_high] < a[ptr_high + 1]) {
				ptr_high++;
			}
			natural_merge(a, b, ptr_low, ptr_middle, ptr_high);
		}
	}
}

void natural_merge(int a[], int b[], int ptr_low, int ptr_middle, int ptr_high) {
	int i = ptr_low, j = ptr_middle + 1, k = ptr_low;
	//���������а������鲢
	while (i <= ptr_middle && j <= ptr_high)b[k++] = a[i] < a[j] ? a[i++] : a[j++];
	//����һ��������Ԫ���Ѿ���ɹ鲢
	while (i <= ptr_middle)b[k++] = a[i++];
	while (j <= ptr_high)b[k++] = a[j++];
}