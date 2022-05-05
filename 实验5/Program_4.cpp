#include <iostream>
using namespace std;
class backpack_solution {
    friend int backpack_solute(int n, int c, int *w, int *v);

  private:
    int c, n, w_now, v_now, v_max, take_num;
    int *order_now, *order_res, *w, *v;

  public:
    void backtrack(int i);
};
int backpack_solute(int n, int c, int *w, int *v);
int main() {
    int n = 5, c = 10;
    int w[5] = {2, 2, 4, 5, 4}; //重量
    int v[5] = {6, 3, 5, 4, 6}; //价值
    int res = backpack_solute(5, 10, w, v);
    cout << "最大价值：" << res << endl;
    system("pause");
    return 0;
}
void backpack_solution::backtrack(int i) {
    if (i == n || w_now + w[order_now[i]] > c) {
        if (v_now > v_max) {
            v_max = v_now;
            for (int k = 0; k < i; k++) {
                order_res[k] = order_now[k];
            }
            take_num = i;
        }
    } else {
        for (int j = i; j < n; j++) {
            swap(order_now[i], order_now[j]);
            if (w_now + w[order_now[i]] <= c) {
                w_now += w[order_now[i]];
                v_now += v[order_now[i]];
                backtrack(i + 1);
                v_now -= v[order_now[i]];
                w_now -= w[order_now[i]];
            }
            swap(order_now[i], order_now[j]);
        }
    }
}
int backpack_solute(int n, int c, int *w, int *v) {
    backpack_solution x;
    x.c = c, x.n = n, x.w = w, x.v = v;
    x.w_now = 0, x.take_num = 0;
    x.v_now = 0, x.v_max = 0;
    x.order_now = new int[n];
    x.order_res = new int[n];
    for (int i = 0; i < n; i++) {
        x.order_now[i] = i;
    }
    x.backtrack(0);
    cout << "放入物品：" << endl;
    for (int i = 0; i < x.take_num; i++) {
        cout << x.order_res[i] + 1 << "  ";
    }
    cout << endl << endl;
    delete[] x.order_res;
    delete[] x.order_now;
    return x.v_max;
}