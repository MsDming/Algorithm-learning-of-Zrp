#include <iostream>
using namespace std;
class travel_solution {
    friend void travel_solute(int (*a)[4], int n);

  private:
    int (*a)[4], n, d_now, best_d, *res_now, *best_res;

  public:
    void backtrack(int depth);
};
void travel_solute(int (*a)[4], int n);
int main() {
    int a[4][4] = {
        {0, 30, 6, 4}, {30, 0, 5, 10}, {6, 5, 0, 20}, {4, 10, 20, 0}};
    travel_solute(a, 4);
    system("pause");
    return 0;
}
void travel_solution::backtrack(int depth) {
    if (depth == n) {
        if (d_now < best_d) {
            best_d = d_now;
            for (int i = 0; i < n; i++) {
                best_res[i] = res_now[i];
            }
        }
    } else {
        for (int i = depth; i < n; i++) {
            swap(res_now[i], res_now[depth]);
            if (a[res_now[depth - 1]][res_now[depth]] &&
                d_now + a[res_now[depth - 1]][res_now[depth]] < best_d) {
                d_now += a[res_now[depth - 1]][res_now[depth]];
                backtrack(depth + 1);
                d_now -= a[res_now[depth - 1]][res_now[depth]];
            }
            swap(res_now[i], res_now[depth]);
        }
    }
}
void travel_solute(int (*a)[4], int n) {
    travel_solution t;
    t.a = a;
    t.n = n;
    t.d_now = 0;
    t.best_d = INT_MAX;
    t.res_now = new int[n]{};
    t.best_res = new int[n]{};
    for (int i = 0; i < n; i++) {
        t.res_now[i] = i;
    }
    t.backtrack(1);
    cout << "最优路径：" << endl;
    for (int i = 0; i < n; i++) {
        cout << t.best_res[i] + 1 << "  ";
    }
    cout << endl;
    cout << "最短路程：" << t.best_d << endl;
    delete[] t.res_now;
    delete[] t.best_res;
}