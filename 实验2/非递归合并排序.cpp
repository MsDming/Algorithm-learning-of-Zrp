#include<iostream>
using namespace std;

void merge_sort(int* a, int n);//�ϲ�����
void merge_pass(int* a, int* b, int n, int merge_len);//һ�˺ϲ�
void merge(int* a, int* b, int ptr_low, int ptr_middle, int ptr_high, int n);//���������кϲ�

int main() {
	int a[10] = { 12,45,-3,78,-29,39,-10,0,25,75 };
	merge_sort(a, 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

void merge_sort(int* a, int n) {
	int* b = new int[n] {};
	int merge_len = 1;
	while (merge_len < n) {
		merge_pass(a, b, n, merge_len);
		merge_len *= 2;
		merge_pass(b, a, n, merge_len);
		merge_len *= 2;
	}
	delete[]b;
}

void merge_pass(int* a, int* b, int n, int merge_len) {
	int ptr_low = 0, ptr_high = ptr_low + merge_len * 2 - 1;//low��high�ֱ�ָ�������������Ԫ���±��βԪ���±�
	while (ptr_high <= n - 1) {
		merge(a, b, ptr_low, ptr_low + merge_len, ptr_high, n);
		ptr_low += merge_len * 2;
		ptr_high += merge_len * 2;
	}
	if (n - ptr_low > merge_len) {	//�ж�һ�������
		merge(a, b, ptr_low, ptr_low + merge_len, ptr_high, n);
		return;
	}
	while (ptr_low < n) {	//ʣ��Ԫ�ز���һ������
		b[ptr_low] = a[ptr_low];
		ptr_low++;
	}
}

void merge(int* a, int* b, int ptr_low, int ptr_middle, int ptr_high, int n) {	//ptr_middleָ�����������к�һ�����Ԫ���±�
	int i = ptr_low, j = ptr_middle, k = ptr_low;
	while (i < ptr_middle && j <= ptr_high && j < n) {
		if (a[i] < a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
		}
	}
	//����һ���Ѿ�����
	while (i < ptr_middle) {
		b[k++] = a[i++];
	}
	while (j <= ptr_high && j < n) {
		b[k++] = a[j++];
	}
}