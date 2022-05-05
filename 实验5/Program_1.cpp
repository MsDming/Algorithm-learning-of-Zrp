#include <iostream>
using namespace std;
class loading_solution {

  private:
    int n, c1, c2, c1_load_now, c2_load_now, res_num;
    int *w, *v_load_now;

  public:
    void backtrack(int depth);
    friend void max_loading(int n, int c1, int c2, int w[]);
};
void max_loading(int n, int c1, int c2, int w[]);
int main() {
    int w1[] = {10, 40, 40};
    int w2[] = {20, 40, 40};
    max_loading(3, 50, 50, w2);
    system("pause");
    return 0;
}

void max_loading(int n, int c1, int c2, int w[]) {
    loading_solution x;
    x.n = 3, x.c1 = c1;
    x.c2 = c2;
    x.w = w;
    x.c1_load_now = 0, x.c2_load_now = 0;
    x.v_load_now = new int[n]{};
    x.res_num = 0;
    x.backtrack(0);
    if (x.res_num == 0) {
        cout << "没有可行的装载方案" << endl;
    }
    delete[] x.v_load_now;
}
void loading_solution::backtrack(int depth) {
    if (depth == n) {
        cout << "装载方案" << ++res_num << "：" << endl;
        for (int i = 0; i < n; i++) {
            cout << "集装箱" << i << "装入c" << v_load_now[i] << endl;
        }
        cout << endl;
    } else {
        if (w[depth] + c1_load_now <= c1) {
            v_load_now[depth] = 1;
            c1_load_now += w[depth];
            backtrack(depth + 1);
            v_load_now[depth] = 0;
            c1_load_now -= w[depth];
        }
        if (w[depth] + c2_load_now <= c2) {
            v_load_now[depth] = 2;
            c2_load_now += w[depth];
            backtrack(depth + 1);
            v_load_now[depth] = 0;
            c2_load_now -= w[depth];
        }
    }
}