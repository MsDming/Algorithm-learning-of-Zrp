#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int greedy_best_dec(int n);

int main() {
    int n;
    cout << "n=";
    cin >> n;
    int res = greedy_best_dec(n);
    cout << "乘积：" << res << endl;
    system("pause");
    return 0;
}

int greedy_best_dec(int n) {
    if (n <= 2)
        return n;
    vector<int> dec;
    int i = 2, temp_sum = 0;
    while (temp_sum + i <= n) {
        temp_sum += i;
        dec.push_back(i);
        ++i;
    }
    if (temp_sum != n) {
        int diff = n - temp_sum;
        int j = dec.size() - 1;
        while (diff) {
            ++dec[j];
            --j;
            --diff;
        }
    }
    int res = dec[0];
    for (int i = 1; i < dec.size(); ++i) {
        res *= dec[i];
    }
    cout << "因子序列：" << endl;
    for (int i = 0; i < dec.size(); ++i) {
        cout << dec[i] << "  ";
    }
    cout << endl;
    return res;
}