#include<iostream>
using namespace std;

void arrange(int n, int depth, int* R);

int main() {
	int n, * R;
	cout << "请输入数组长度n："; cin >> n;
	R = new int[n];
	cout << "请依次输入每个元素：";
	for (int i = 0; i < n; i++) {
		cin >> R[i];
	}
	arrange(n, 0, R);
	delete[]R;
	return 0;
}

void arrange(int n, int depth, int* R) {//depth代表递归调用深度
	if (n == depth) {//若数组长度与递归调用深度相等，则输出该序列
		for (int i = n; i > 0; --i) {
			cout << *(R - i) << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < n - depth; i++) {
			if (i > 0 && R[0] == R[i])	continue;//避免重复情况
			swap(R[0], R[i]);
			arrange(n, depth + 1, R + 1);
			swap(R[0], R[i]);
		}
	}
}