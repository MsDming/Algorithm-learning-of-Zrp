#include<iostream>
#define MINNUM -2147483648
using namespace std;

int max_sub_sum(int* s, int len);

int main() {
	int s[] = { -2,11,-4,13,-5,-2 };
	int len = sizeof(s) / sizeof(s[0]);
	cout << "最大子段和为：" << max_sub_sum(s, len);
	return 0;
}

int max_sub_sum(int* s, int len) {
	int sum_res = MINNUM;
	int b = MINNUM;
	for (int i = 0; i < len; i++) {
		if (b > 0) {
			b += s[i];
		}
		else {
			b = s[i];
		}
		if (sum_res < b) {
			sum_res = b;
		}
	}
	return sum_res;
}