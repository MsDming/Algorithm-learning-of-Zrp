#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

float greedy_backpack(float* v, float* w, int n, float cap);
void v_w_sort(float* v, float* w, int* Id, int n);
bool cmp(pair<float, float> x, pair<float, float> y);

int main() {
    float v[] = {30, 30, 60, 75, 300};
    float w[] = {10, 15, 40, 30, 60};
    float res = greedy_backpack(v, w, sizeof(v) / sizeof(v[0]), 90);
    cout << "最优解背包总价值：" << res << endl;
    system("pause");
    return 0;
}

float greedy_backpack(float* v, float* w, int n, float cap) {
    int* Id = new int[n];
    float weight_sum{}, value_sum{}, per{};
    int i{};
    vector<int> res_id;
    for (int i = 0; i < n; i++) {
        Id[i] = i + 1;
    }
    v_w_sort(v, w, Id, n);
    while (i < n && weight_sum + w[i] <= cap) {
        weight_sum += w[i];
        value_sum += v[i];
        res_id.push_back(Id[i]);
        i++;
    }
    if (weight_sum < cap && i < n) {
        per = (cap - weight_sum) / w[i];
        value_sum += per * v[i];
        res_id.push_back(Id[i]);
        cout << "依次放入物品编号：";
        for (int i = 0; i < res_id.size(); i++) {
            cout << res_id[i] << "  ";
        }
        cout << endl;
        cout << "最后一种物品放入" << per * 100 << "%" << endl;
        delete[] Id;
        return value_sum;
    }
    cout << "依次放入物品编号：";
    for (int i = 0; i < res_id.size(); i++) {
        cout << res_id[i] << "  ";
    }
    delete[] Id;
    return value_sum;
}

void v_w_sort(float* v, float* w, int* Id, int n) {
    float* v_divi_w = new float[n]{};
    for (int i = 0; i < n; i++) {
        v_divi_w[i] = v[i] / w[i];
    }
    pair<float, float> pairt[n];
    for (int i = 0; i < n; i++) {
        pairt[i].first = v_divi_w[i];
        pairt[i].second = v[i];
    }
    sort(pairt, pairt + n, cmp);
    for (int i = 0; i < n; i++) {
        v[i] = pairt[i].second;
    }
    for (int i = 0; i < n; i++) {
        pairt[i].first = v_divi_w[i];
        pairt[i].second = w[i];
    }
    sort(pairt, pairt + n, cmp);
    for (int i = 0; i < n; i++) {
        w[i] = pairt[i].second;
    }
    for (int i = 0; i < n; i++) {
        pairt[i].first = v_divi_w[i];
        pairt[i].second = Id[i];
    }
    sort(pairt, pairt + n, cmp);
    for (int i = 0; i < n; i++) {
        Id[i] = pairt[i].second;
    }
    delete[] v_divi_w;
}

bool cmp(pair<float, float> x, pair<float, float> y) {
    return x.first > y.first;
}