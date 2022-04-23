#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void greedy_tape(int* len, int n, int L);
int main() {
    int len[] = {2, 3, 13, 8, 80, 20}, L = 50;
    greedy_tape(len, sizeof(len) / sizeof(len[0]), L);
    system("pause");
    return 0;
}

void greedy_tape(int* len, int n, int L) {
    int* Id = new int[n];
    for (int i = 0; i < n; i++) {
        Id[i] = i + 1;
    }
    vector<int> res_id;
    pair<int, int> pairt[n];
    for (int i = 0; i < n; i++) {
        pairt[i].first = len[i];
        pairt[i].second = Id[i];
    }
    sort(pairt, pairt + n);
    int i = 0, len_sum = 0;
    while (i < n && len_sum + pairt[i].first <= L) {
        res_id.push_back(pairt[i].second);
        len_sum += pairt[i].first;
        i++;
    }
    cout << "可存储的程序数量：" << res_id.size() << endl;
    cout << "存储的磁带编号：" << endl;
    for (int i = 0; i < res_id.size();i++){
        cout << res_id[i] << "  ";
    }
    cout << endl;
    delete[] Id;
}