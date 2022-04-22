#include<iostream>
using namespace std;

void MinWeightTriangulation(int n, int** hash_map, int** res);
void print_res(int i, int j, int** res);//构建并输出最优解
int W(int i, int j, int k);//计算三角形周长

int weight[6][6] = {
		{ 0, 2, 2, 3, 1, 4 },
		{ 2, 0, 1, 5, 2, 3 },
		{ 2, 1, 0, 2, 1, 4 },
		{ 3, 5, 2, 0, 6, 2 },
		{ 1, 2, 1, 6, 0, 1 },
		{ 4, 3, 4, 2, 1, 0 }
};

int main() {
	int** hash_map = new int* [6];
	int** res = new int* [6];
	for (int i = 0; i <= 5; i++) {
		hash_map[i] = new int[6]{};
		res[i] = new int[6]{};
	}
	MinWeightTriangulation(5, hash_map, res);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cout << hash_map[i][j] << '\t';
		}cout << endl << endl;
	}
	cout << "最优剖分三角形周长之和：" << hash_map[1][5] << endl;
	print_res(1, 5, res);
	for (int i = 0; i <= 5; i++) {
		delete[]hash_map[i];
		delete[]res[i];
	}
	delete[]hash_map;
	delete[]res;
	return 0;
}

void MinWeightTriangulation(int n, int** hash_map, int** res) {
	for (int i = 1; i <= n; i++) {//初始化dp数组
		hash_map[i][i] = 0;
	}
	for (int r = 2; r <= n; r++) {
		for (int i = 1; i <= n - r + 1; i++) {
			int j = i + r - 1;
			hash_map[i][j] = hash_map[i + 1][j] + W(i - 1, i, j);
			res[i][j] = i;
			for (int k = i + 1; k < i + r - 1; k++) {
				if (hash_map[i][k] + hash_map[k + 1][j] + W(i - 1, k, j) < hash_map[i][j]) {
					hash_map[i][j] = hash_map[i][k] + hash_map[k + 1][j] + W(i - 1, k, j);
					res[i][j] = k;
				}
			}
		}
	}
}

void print_res(int i, int j, int** res) {
	if (i == j) { return; }
	else {//递归输出最优解
		cout << "三角形：v" << i - 1 << ",v" << res[i][j] << ",v" << j << "\t周长：" << W(i - 1, res[i][j], j) << endl;
		print_res(i, res[i][j], res);
		print_res(res[i][j] + 1, j, res);
	}
}

int W(int i, int j, int k) {
	return weight[i][j] + weight[i][k] + weight[j][k];
}