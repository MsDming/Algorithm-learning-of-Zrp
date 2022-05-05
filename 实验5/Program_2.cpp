#include <iostream>
using namespace std;
class arrange_solution {
  private:
    int *t1, *t2;
    int *range_res_now, *range_res, *F1, *F2;
    int n, min_sum_now, min_sum;

  public:
    friend void arrange_solute(int n, int *t1, int *t2);
    void backtrack(int depth);
};
void arrange_solute(int n, int *t1, int *t2);
int main() {
    int n = 3, t1[] = {2, 3, 2}, t2[] = {1, 1, 3};
    arrange_solute(n, t1, t2);
    system("pause");
    return 0;
}

void arrange_solution::backtrack(int depth) {
    if (depth > n && min_sum_now < min_sum) {
        min_sum = min_sum_now;
        for (int i = 1; i <= n; i++) {
            range_res[i] = range_res_now[i];
        }
    } else {
        for (int i = depth; i <= n; i++) {
            swap(range_res_now[depth], range_res_now[i]);
            if (min_sum_now + t2[range_res_now[depth] - 1] +
                    max(F1[depth], F2[depth - 1]) <
                min_sum) {
                F1[depth] = F1[depth - 1] + t1[range_res_now[depth] - 1];
                F2[depth] = t2[range_res_now[depth] - 1] +
                            max(F1[depth], F2[depth - 1]);
                min_sum_now += F2[depth];
                backtrack(depth + 1);
                min_sum_now -= F2[depth];
            }
            swap(range_res_now[depth], range_res_now[i]);
        }
    }
}

void arrange_solute(int n, int *t1, int *t2) {
    arrange_solution x;
    x.n = n;
    x.min_sum = INT_MAX;
    x.min_sum_now = 0;
    x.t1 = t1;
    x.t2 = t2;
    x.F1 = new int[n + 1]{};
    x.F2 = new int[n + 1]{};
    x.range_res = new int[n + 1]{};
    x.range_res_now = new int[n + 1]{};
    for (int i = 1; i <= n; i++) {
        x.range_res_now[i] = i;
    }
    x.backtrack(1);
    cout << "最优调度" << endl;
    for (int i = 1; i <= n; i++) {
        cout << x.range_res[i] << "  ";
    }
    cout << endl;
    cout << "完成时间和：" << x.min_sum << endl;
    delete[] x.F1;
    delete[] x.F2;
    delete[] x.range_res;
    delete[] x.range_res_now;
}