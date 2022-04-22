#include<iostream>
#include<ctime>
using namespace std;

int linear_time_select(int a[], int i, int j, int k);
int random_division(int a[], int i, int j);//对a[i]~a[j]的元素进行一次随机划分，返回划分点在a数组中是第几小的元素

int main() {
	int a[80] = { 3, 1, 7, 6, 5, 9, 8, 2, 0, 4, 13, 11, 17, 16, 15, 19, 18, 12, 10, 14, 23, 21, 27, 26, 25, 29, 28, 
		22, 20, 24, 33, 31, 37, 36, 35, 39, 38, 32, 30, 34, 43, 41, 47, 46, 45, 49, 48, 42, 40, 44, 53, 51, 57, 56, 
		55, 59, 58, 52, 50, 54, 63, 61, 67, 66, 65, 69, 68, 62, 60, 64, 73, 71, 77, 76, 75, 79, 78, 72, 70, 74 };
	int n = sizeof(a) / sizeof(a[0]);
	//随机数种子
	unsigned seed;
	seed = time(0);
	srand(seed);
	int k; cout << "找出数组中第k小的数，请输入k："; cin >> k;
	int res = linear_time_select(a, 0, n - 1, k - 1);
	cout << res;
	return 0;
}

int linear_time_select(int a[], int i, int j, int k) {
	int divi_res = -1;
	divi_res = random_division(a, i, j);
	if (divi_res == k) {
		return a[k];
	}
	else if (divi_res > k) {//目标元素小于找到的划分点
		j = divi_res;
		return linear_time_select(a, i, j, k);
	}
	else {//目标元素大于找到的划分点
		i = divi_res;
		return linear_time_select(a, i, j, k);
	}
	
}

int random_division(int a[], int i, int j) {
	int rd = rand() % (j - i + 1) + i;
	swap(a[rd], a[i]);
	while (i < j) {
		int temp = a[i];
		while (a[j] >= temp && i < j)j--;
		if (i == j) {
			a[i] = temp;
			break;
		}
		else {
			swap(a[i], a[j]);
		}
		while (a[i] < temp && i < j)i++;
		if (i == j) {
			a[i] = temp;
			break;
		}
		else {
			swap(a[i], a[j]);
		}
	}
	return i;
}