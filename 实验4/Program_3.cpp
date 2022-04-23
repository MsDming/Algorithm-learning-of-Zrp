#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void greedy_load(int* w, int n, int w_limit);

int main() {
    int w[6] = {100, 15, 27, 25, 30, 20}, w_limit = 100;
    greedy_load(w, sizeof(w)/sizeof(w[0]), 100);
    system("pause");
    return 0;
}

void greedy_load(int* w, int n, int w_limit) {
    int* Id = new int[n];
    vector<int> res_id;
    for (int i = 0; i < n; i++) {
        Id[i] = i + 1;
    }
    pair<int, int> pairt[n];
    for (int i = 0; i < n; i++) {
        pairt[i].first = w[i];
        pairt[i].second = Id[i];
    }
    sort(pairt, pairt + n);
    for (int i = 0; i < n; i++) {
        w[i] = pairt[i].first;
        Id[i] = pairt[i].second;
    }
    int i = 0, w_sum = 0;
    while (i < n && w_sum < w_limit) {
        if (w[i] + w_sum < w_limit) {
            res_id.push_back(Id[i]);
            w_sum += w[i];
        }
        i++;
    }
    cout << "编号：" << '\t';
    for (int j = 0; j < res_id.size(); j++) {
        cout << res_id[j] << "  ";
    }
    cout << endl;
    cout << "重量：" << '\t';
    for (int j = 0; j < res_id.size(); j++) {
        cout << w[j] << "  ";
    }
    cout << endl;
    cout << "总重量：" << w_sum << endl;
    cout << "总数量：" << res_id.size() << endl;
    delete[] Id;
}