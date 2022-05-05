#include <iostream>
using namespace std;
class Clique {
    friend void Clique_solute(int (*a)[5], int n);

  private:
    int (*a)[5], n, *res_now, n_now, cn, bestn, *best_res;

  public:
    void backtrack(int depth);
    bool is_connected(int depth);
};
void Clique_solute(int (*a)[5], int n);
int main() {
    int a[5][5] = {{0, 1, 0, 1, 1},
                   {1, 0, 1, 0, 1},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 0, 1},
                   {1, 1, 1, 1, 0}};
    Clique_solute(a, 5);
    system("pause");
    return 0;
}

void Clique::backtrack(int depth) {
    if (depth == n || !is_connected(depth)) {
        if (cn > bestn) {
            bestn = cn;
            for (int i = 0; i < bestn; i++) {
                best_res[i] = res_now[i];
            }
        }
    } else {
        for (int i = depth; i < n; i++) {
            swap(res_now[i], res_now[depth]);
            if (is_connected(depth) && cn + n - depth >= bestn) {
                cn++;
                backtrack(depth + 1);
                cn--;
            }
            swap(res_now[i], res_now[depth]);
        }
    }
}

bool Clique::is_connected(int depth) {
    for (int i = 0; i < depth; i++) {
        if (a[res_now[depth]][res_now[i]] == 0) {
            return false;
        }
    }
    return true;
}

void Clique_solute(int (*a)[5], int n) {
    Clique c;
    c.a = a;
    c.n = n;
    c.cn = 0;
    c.bestn = 0;
    c.res_now = new int[n]{};
    c.best_res = new int[n]{};
    for (int i = 0; i < n; i++) {
        c.res_now[i] = i;
        c.best_res[i] = i;
    }
    c.backtrack(0);
    cout << "最大团节点个数：" << c.bestn << endl;
    cout << "最大团：" << endl;
    for (int i = 0; i < c.bestn; i++) {
        cout << c.best_res[i] + 1 << "  ";
    }
    cout << endl << endl;
    delete[] c.res_now;
    delete[] c.best_res;
}