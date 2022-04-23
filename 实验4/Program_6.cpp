#include <iostream>
#include <vector>
using namespace std;

void greedy_gas(int* len, int n, int k);
int main() {
    int n = 7, k = 7;
    int len[8] = {1, 2, 3, 4, 5, 1, 6, 6};
    greedy_gas(len, n, k);
    system("pause");
    return 0;
}

void greedy_gas(int* len, int n, int k) {
    vector<int> res;
    int temp_dist{};
    for (int i = 0; i < k; i++) {
        if (temp_dist + len[i] <= n) {
            temp_dist += len[i];
        } else {
            res.push_back(i);
            temp_dist = 0;
            --i;
        }
    }
    cout << "最少加油次数：" << res.size() << endl;
    cout << "加油站编号：" << endl;
    for (int i = 0; i < res.size();++i){
        cout << res[i] << "  ";
    }
    cout << endl;
}