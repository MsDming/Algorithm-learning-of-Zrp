#include<iostream>
using namespace std;

void arr_trans(int a[], int n, int k);
void my_swap(int& a, int& b);//自己写的两元素交换函数，保证空间复杂度为O(1)

int main() {
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int n = sizeof(a) / sizeof(a[0]), k = 4;
	arr_trans(a, n, k);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
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