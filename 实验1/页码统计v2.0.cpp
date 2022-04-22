#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//页码统计
void fuc(string str, int* res);
//删除前导0
void del_zero(string str, int* res);
//打印结果
void print_res(int* res);

int main() {
	string str;
	int res[10]{};
	cout << "请输入页码n(1<=n<=10^9)："; cin >> str;
	fuc(str, res);
	del_zero(str, res);
	print_res(res);
	return 0;
}

void fuc(string str, int* res) {
	int str_len = str.length(), high = str[0] - '0';
	if (str_len == 1) {
		for (int i = 0; i <= high; i++) {
			res[i]++;
		}
		return;
	}

	string others = str.substr(1);
	//第一部分
	for (int i = 0; i < 10; i++) {
		res[i] += high * (str_len - 1) * pow(10, (str_len - 2));
	}

	//第二部分
	for (int i = 0; i < high; i++) {
		res[i] += pow(10, str_len - 1);
	}
	int others_ = atoi(others.c_str());
	res[high] += others_ + 1;

	//第三部分
	res[0] += (str_len - (to_string(others_).length()) - 1) * (others_ + 1);
	fuc(to_string(others_), res);
}

void del_zero(string str, int* res) {
	res[0] -= (pow(10, str.length()) - 1) / 9;
}

void print_res(int* res) {
	for (int i = 0; i < 10; i++) {
		cout << i << "出现次数：" << res[i] << endl;
	}
}