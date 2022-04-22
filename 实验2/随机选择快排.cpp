#include<iostream>
#include<ctime>
using namespace std;

void rand_quick_sort(int a[], int n);

int main() {
	int a[10] = { 12,45,-3,78,-29,39,-10,0,25,75 };
	int n = sizeof(a) / sizeof(a[0]);
	/*���������*/
	unsigned seed;
	seed = time(0);
	srand(seed);
	rand_quick_sort(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

void rand_quick_sort(int a[], int n) {
	if (n == 1 || n == 0)return;//�������
	int l = 0, r = n - 1;
	int rd = rand() % n;//���ѡȡ�궨��
	swap(a[l], a[rd]);
	while (l < r) {
		int temp = a[l];//�洢�궨������
		/*r����*/
		while (a[r] >= temp && l < r)r--;
		if (l == r) {//��ֹ���������ѭ��
			a[l] = temp;
			break;
		}
		else {
			swap(a[l], a[r]);
		}
		/*l����*/
		while (a[l] < temp && l < r)l++;
		if (l == r) {//��ֹ���������ѭ��
			a[l] = temp;
			break;
		}
		else {
			swap(a[l], a[r]);
		}
	}
	/*�ݹ����*/
	rand_quick_sort(a, l + 1);
	rand_quick_sort(a + l + 1, n - l - 1);
}