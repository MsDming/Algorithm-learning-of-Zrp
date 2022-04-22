#include<iostream>
using namespace std;

int half_set(int n);

int main() {
	int n;
	cout << "请输入n(0<n<200)：";
	cin >> n;
	cout << half_set(n);
	return 0;
}

int half_set(int n) {
	int res = 1;//初始元素本身算一个
	if (n > 1) {
		for (int i = 1; i <= n / 2; i++) {
			res += half_set(i);
			res--;//去除重复元素
		}
		res += n / 2;
	}
	return res;
}