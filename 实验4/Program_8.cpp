#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void greedy_min_num(int n, int k);

int main() {
    int n, k;
    cout << "n=";
    cin >> n;
    cout << "k=";
    cin >> k;
    greedy_min_num(n, k);
    system("pause");
    return 0;
}

void greedy_min_num(int n, int k) {
    vector<int> num;
    vector<input_iterator_tag> delete_ptr(k);
    while (n) {
        num.push_back(n % 10);
        n /= 10;
    }
    reverse(num.begin(), num.end());
    for (int i = 0; i < k; ++i) {
        int temp = 0;
        vector<int>::iterator iter = num.begin();
        for (int j = 1; j < num.size(); ++j) {
            if(num[j]>num[temp]){
                temp = j;
            }
        }
        num.erase(iter + temp);
    }
    int res{};
    for (int i = 0; i < num.size();++i){
        res += num[i] * pow(10, num.size() - i - 1);
    }
    cout << "最小新数：" << res << endl;
}