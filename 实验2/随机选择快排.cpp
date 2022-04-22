#include<iostream>
#include<ctime>
using namespace std;

void rand_quick_sort(int a[], int n);

int main() {
	int a[10] = { 12,45,-3,78,-29,39,-10,0,25,75 };
	int n = sizeof(a) / sizeof(a[0]);
	/*随机数种子*/
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
	if (n == 1 || n == 0)return;//极简单情况
	int l = 0, r = n - 1;
	int rd = rand() % n;//随机选取标定点
	swap(a[l], a[rd]);
	while (l < r) {
		int temp = a[l];//存储标定点数字
		/*r向左*/
		while (a[r] >= temp && l < r)r--;
		if (l == r) {//终止情况，跳出循环
			a[l] = temp;
			break;
		}
		else {
			swap(a[l], a[r]);
		}
		/*l向右*/
		while (a[l] < temp && l < r)l++;
		if (l == r) {//终止情况，跳出循环
			a[l] = temp;
			break;
		}
		else {
			swap(a[l], a[r]);
		}
	}
	/*递归调用*/
	rand_quick_sort(a, l + 1);
	rand_quick_sort(a + l + 1, n - l - 1);
}