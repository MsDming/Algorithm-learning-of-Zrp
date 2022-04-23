#include <algorithm>
#include <iostream>
using namespace std;

void greedy_service(int* t, int n);

int main() {
    int t[] = {56, 12, 1, 99, 1000, 234, 33, 55, 99, 812};
    greedy_service(t, sizeof(t) / sizeof(t[0]));
    system("pause");
    return 0;
}

void greedy_service(int* t, int n) {
    int* Id = new int[n];
    for (int i = 0; i < n; i++) {
        Id[i] = i + 1;
    }
    pair<int, int> pairt[n];
    for (int i = 0; i < n; i++) {
        pairt[i].first = t[i];
        pairt[i].second = Id[i];
    }
    sort(pairt, pairt + n);
    int t_wait = 0;
    for (int i = 0; i < n - 1; i++) {
        t_wait += pairt[i].first * (n - 1 - i);
    }
    t_wait /= n;
    cout << "最优服务安排次序：" << endl;
    for (int i = 0; i < n; i++) {
        cout << pairt[i].second << "  ";
    }
    cout << endl;
    cout << "平均等待时间：" << t_wait << endl;
    delete[] Id;
}