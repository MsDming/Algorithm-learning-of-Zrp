#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void greedy_interval(int* len, int n, int k);
void output_res(int* len, int n, int k, vector<int> res);
int main() {
    int len[] = {1, 2, 3, 4, 5, -2, 6};
    int n = 7, k = 3;
    greedy_interval(len, n, k);
    system("pause");
    return 0;
}

void greedy_interval(int* len, int n, int k) {
    sort(len, len + n);
    int temp_dist{};
    vector<int> res;
    res.push_back(len[0]);
    for (int i = 1; i < n; ++i) {
        if (temp_dist + (len[i] - len[i - 1]) <= k) {
            temp_dist += (len[i] - len[i - 1]);
        } else {
            res.push_back(len[i]);
            if (i != n - 1) {
                temp_dist = 0;
            }
        }
    }
    cout << "最少区间数：" << res.size() << endl;
    output_res(len, n, k, res);
}

void output_res(int* len, int n, int k, vector<int> res) {
    for (int i = 0, j = 0; i < res.size(); i++) {
        int temp_dist = 0;
        cout << "区间：[" << res[i] << "," << res[i] + 3 << "]" << endl
             << "覆盖点：";
        do{
            cout << len[j] << "  ";
            temp_dist += len[j + 1] - len[j];
            ++j;
        } while (j < n - 1 && temp_dist <= k);
        cout << endl << endl;
    }
}