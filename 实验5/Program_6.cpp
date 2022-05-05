#include <iostream>
using namespace std;
class m_color {
    friend void m_color_solute(int (*a)[5], int m, int n);

  private:
    int (*a)[5], n, m, *res, res_num;

  public:
    void backtrack(int depth);
    bool color_ok(int depth);
    void print_res();
};
void m_color_solute(int (*a)[5], int m, int n);
int main() {
    int a[5][5] = {{0, 1, 1, 1, 0},
                   {1, 0, 1, 1, 1},
                   {1, 1, 0, 1, 0},
                   {1, 1, 1, 0, 1},
                   {0, 1, 0, 1, 0}};
    m_color_solute(a, 4, 5);
    system("pause");
    return 0;
}

void m_color::backtrack(int depth) {
    if (depth == n) {
        res_num++;
        print_res();
    } else {
        for (int i = 0; i < m; i++) {
            res[depth] = i;
            if (color_ok(depth)) {
                backtrack(depth + 1);
            }
        }
    }
}

bool m_color::color_ok(int depth) {
    for (int i = 0; i < depth; i++) {
        if (a[i][depth] && res[i] == res[depth]) {
            return false;
        }
    }
    return true;
}

void m_color::print_res() {
    cout << "第" << res_num << "种着色方案：" << endl;
    for (int i = 0; i < n; i++) {
        cout << "节点" << i + 1 << '\t';
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "颜色" << res[i] + 1 << '\t';
    }
    cout << endl;
}

void m_color_solute(int (*a)[5], int m, int n) {
    m_color x;
    x.a = a;
    x.n = n;
    x.m = m;
    x.res_num = 0;
    x.res = new int[n]{};
    x.backtrack(0);
    if (x.res_num == 0) {
        cout << "无解决方案" << endl;
    }
    delete[] x.res;
}