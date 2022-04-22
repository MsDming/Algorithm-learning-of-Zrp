#include<iostream>
using namespace std;

template<class T>//使用模板
void binary_search(T* a, T target, int n, int& i, int& j);

int main() {
	int a[10] = { 12,45,57,78,82,89,95,98,113,125 }, target, i = -1, j = -1;
	cout << "请输入要查找的数字：";
	while (cin >> target) {
		binary_search(a, target, 10, i, j);
		cout << "i=" << i << endl << "j=" << j << endl;
		cout << "请输入要查询的数字：";
	}
		
	return 0;
}

template<class T>
void binary_search(T* a, T target, int n, int& i, int& j) {
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == target) {//查找成功
			i = j = mid;
			cout << "查找成功！" << endl;
			return;
		}
		else if (a[mid] < target) {//目标元素在右半区
			low = mid + 1;
		}
		else {//目标元素在左半区
			high = mid - 1;
		}
	}
	i = high; j = low;//查找失败，设置i，j的数值
	cout << "查找失败" << endl;
}