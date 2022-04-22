#include<iostream>
using namespace std;

template<class T>//尝试使用模板
int binary_search(T* a, T target, int n);

int main() {
	int a[10] = { 12,45,57,78,82,89,95,98,113,125 }, target;
	cout << "请输入要查找的数字：";
	while (cin >> target) {
		int res = binary_search(a, target, 10);
		if (res != -1) {
			cout << "查找结果为：" << res << endl;
		}
		cout << "请输入要查找的数字：";
	}
	return 0;
}

template<class T>
int binary_search(T* a, T target, int n) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == target) {
			return mid;//找到目标元素
		}
		else if (a[mid] < target) {//目标元素在右半区
			low = mid + 1;
		}
		else {//目标元素在左半区
			high = mid - 1;
		}
	}
	cout << "查找失败" << endl;
	return -1;
}