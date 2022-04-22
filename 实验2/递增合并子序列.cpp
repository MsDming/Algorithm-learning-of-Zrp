#include<iostream>
using namespace std;

void limited_merge(int a[], int n, int k);
void arr_trans(int a[], int n, int k);//基于数组换位实现的子序列合并
void my_swap(int& a, int& b);

int main() {
	int a[10] = { 4,7,9,10,1,3,6,8,12,16 };
	int k = 4, n = sizeof(a) / sizeof(a[0]);
	limited_merge(a, n, k);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

void limited_merge(int a[], int n, int k) {
	int i = 0, j = k;
	while (j < n) {
		while (a[i] < a[j] && i < j) { i++; }
		if (i == j) { return; }
		arr_trans(a + i, k - i + 1, k - i);
		k++;
		j++;
	}
}

void arr_trans(int a[], int n, int k) {
	if (n == k * 2) {
		for (int i = 0; i < k; i++) {
			my_swap(a[i], a[i + k]);
		}
		return;
	}
	else if (n > k * 2) {
		for (int i = 0; i < k; i++) {
			my_swap(a[i], a[i + k]);
		}
		arr_trans(a + k, n - k, k);
	}
	else {
		for (int i = 0; i < n - k; i++) {
			my_swap(a[i], a[i + k]);
		}
		arr_trans(a + n - k, k, k * 2 - n);
	}
}

void my_swap(int& a, int& b) {
	int temp = b;
	b = a;
	a = temp;
}