#include<iostream>
using namespace std;

void longest_common_subsequence(int s1[], int s2[], int len1, int len2, int** hash_map, string** res);

int main() {
	int s1[] = { 1,3,4,5,6,7,7,8 }, s2[] = { 3,5,7,4,8,6,7,8,2 };
	int len1 = sizeof(s1) / sizeof(s1[0]), len2 = sizeof(s2) / sizeof(s2[0]);
	int** hash_map = new int* [len1 + 1];//hash_map数组作为dp数组
	string** res = new string * [len1 + 1];//res数组用于构建最优解
	for (int i = 0; i <= len1; i++) {
		hash_map[i] = new int[len2 + 1]{};
		res[i] = new string[len2 + 1]{};
	}
	longest_common_subsequence(s1, s2, len1, len2, hash_map, res);
	for (int i = 0; i <= len1; i++) {
		delete[]hash_map[i];
		delete[]res[i];
	}
	delete[]hash_map;
	delete[]res;
	return 0;
}

void longest_common_subsequence(int s1[], int s2[], int len1, int len2, int** hash_map, string** res) {
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				hash_map[i][j] = hash_map[i - 1][j - 1] + 1;
				res[i][j] = res[i - 1][j - 1] + char(s1[i - 1] + '0');
			}
			else if (hash_map[i][j - 1] >= hash_map[i - 1][j]) {
				hash_map[i][j] = hash_map[i][j - 1];
				res[i][j] = res[i][j - 1];
			}
			else {
				hash_map[i][j] = hash_map[i - 1][j];
				res[i][j] = res[i - 1][j];
			}
		}
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			cout << hash_map[i][j] << "\t";
		}cout << endl << endl;
	}
	cout << "最长公共子序列：";
	cout << res[len1][len2] << endl;
}