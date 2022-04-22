#include<iostream>
using namespace std;

int fuc(int x, int y);
int str_code(string str);

int main() {
	char alphabet[27];
	for (int i = 1; i < 27; i++) {
		alphabet[i] = 'a' + i;
	}
	string str{};
	cout << "请输入一个长度不超过6的升序字符串：";
	cin >> str;
	cout << str_code(str) << endl;
	return 0;
}

int fuc(int x, int y) {
	if (y == 1) {
		return 27 - x;
	}
	else {
		int res{};
		for (int i = x; i <= 27 - y; i++) {
			res += fuc(i + 1, y - 1);
		}
		return res;
	}
}

int str_code(string str) {
	int str_len = str.length(), res{}, * ch_code;
	ch_code = new int[str_len + 1];
	for (int i = 1; i <= str_len; i++) {
		ch_code[i] = str[i - 1] - 'a' + 1;
	}
	for (int i = 1; i < str_len; i++) {
		res += fuc(1, i);
	}
	res += (fuc(1, str_len) - fuc(ch_code[1], str_len));
	for (int i = 1; i < str_len; i++) {
		res += (fuc(ch_code[i] + 1, str_len - 1) - fuc(ch_code[i + 1], str_len - 1));
	}
	res++;
	delete[]ch_code;
	return res;
}