#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<string> Gray_code(int n);

int main() {
	int n;
	cout << "������n(0<n<=10)��"; cin >> n;
	vector<string>res(pow(2, n));
	res = Gray_code(n);
	for (int i = 0; i < pow(2, n); i++) {
		cout << res[i] << "  ";
	}
	return 0;
}

vector<string> Gray_code(int n) {
	if (n == 1) {
		vector<string>res;
		res.push_back("0");
		res.push_back("1");
		return res;
	}
	else {
		vector<string>res;
		vector<string>v;
		v = Gray_code(n - 1);
		for (int i = 0; i < pow(2, n - 1); i++) {
			res.push_back("0");
			res[i] += v[i];
		}
		for (int i = 0; i < pow(2, n - 1); i++) {
			res.push_back("1");
			res[i + pow(2, n - 1)] += v[pow(2, n - 1) - i - 1];
		}
		return res;
	}
}