#include <iostream>
using namespace std;
class n_jobs_solution {
    friend void n_jobs_solute(int n, int (*cost_tab)[3]);

  private:
    int n, (*cost_tab)[3], *arrange_now, *best_arrange, cost_now, min_cost;

  public:
    void backtrack(int depth);
};
void n_jobs_solute(int n, int (*cost_tab)[3]);
int main() {
    int cost_tab[][3] = {{10, 2, 3}, {2, 3, 4}, {3, 4, 5}};
    n_jobs_solute(3, cost_tab);
    system("pause");
    return 0;
}

void n_jobs_solution::backtrack(int depth) {
    if (depth == n) {
        if (cost_now < min_cost) {
            min_cost = cost_now;
            for (int i = 0; i < n; i++) {
                best_arrange[i] = arrange_now[i];
            }
        }
    } else {
        for (int i = depth; i < n; i++) {
            swap(arrange_now[depth], arrange_now[i]);
            if (cost_now + cost_tab[depth][arrange_now[depth]] < min_cost) {
                cost_now += cost_tab[depth][arrange_now[depth]];
                backtrack(depth + 1);
                cost_now -= cost_tab[depth][arrange_now[depth]];
            }
            swap(arrange_now[depth], arrange_now[i]);
        }
    }
}

void n_jobs_solute(int n, int (*cost_tab)[3]) {
    n_jobs_solution x;
    x.n = n;
    x.cost_now = 0;
    x.min_cost = INT_MAX;
    x.cost_tab = cost_tab;
    x.arrange_now = new int[n]{};
    x.best_arrange = new int[n]{};
    for (int i = 0; i < n; i++) {
        x.arrange_now[i] = i;
    }
    x.backtrack(0);
    cout << "最小花费：" << x.min_cost << endl << endl;
    cout << "工人安排：" << endl;
    for (int i = 0; i < n; i++) {
        cout << "工作" << i + 1 << "  ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "工人" << x.best_arrange[i] + 1 << "  ";
    }
    cout << endl << endl;
    delete[] x.arrange_now;
    delete[] x.best_arrange;
}