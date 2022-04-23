#include <iostream>
#include <vector>
using namespace std;

int greedy(int* s, int* f, int n);
void s_f_sort(int* s, int* f, int* Id, int n);
int main() {
    int s[11] = {3, 5, 6, 8, 8, 2, 12, 1, 3, 0, 5};
    int f[11] = {8, 9, 10, 11, 12, 13, 14, 4, 5, 6, 7};
    int res = greedy(s, f, sizeof(s) / sizeof(s[0]));
    cout << "元素个数：" << res << endl;
    system("pause");
    return 0;
}

int greedy(int* s, int* f, int n) {
    int* Id = new int[n];
    for (int i = 0; i < n; i++) {
        Id[i] = i;
    }
    s_f_sort(s, f, Id, n);
    vector<int> res{};
    res.push_back(Id[0]);
    int temp = f[0];
    for (int i = 1; i < n; i++) {
        if (s[i] >= temp) {
            res.push_back(Id[i]);
            temp = f[i];
        }
    }
    cout << "最优解活动序号：" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] + 1 << "  ";
    }
    cout << endl;
    delete[] Id;
    return res.size();
}

void s_f_sort(int* s, int* f, int* Id, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (f[j] > f[j + 1]) {
                swap(f[j], f[j + 1]);
                swap(s[j], s[j + 1]);
                swap(Id[j], Id[j + 1]);
            }
        }
    }
}