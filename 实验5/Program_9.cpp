#include <iostream>
using namespace std;
class subset_sum {
    friend void subset_sum_solute(int *S, int n, int c);

  private:
    int *S, n, c, sum_now, *v_res, solution_sum;

  public:
    void backtrack(int depth);
};
void subset_sum_solute(int *S, int n, int c);
int main() {
    int S1[5] = {2, 2, 6, 5, 4}, c1 = 10;
    int S2[5] = {1, 2, 8, 3, 9}, c2 = 14;
    subset_sum_solute(S1, 5, c1);
    subset_sum_solute(S2, 5, c2);
    system("pause");
    return 0;
}
void subset_sum::backtrack(int depth) {
    if (depth == n) {
        if (sum_now == c) {
            cout << "解" << ++solution_sum << "：" << endl;
            for (int i = 0; i < n; i++) {
                if (v_res[i]) {
                    cout << S[i] << "  ";
                }
            }
            cout << endl;
        }
    } else {
        if (sum_now + S[depth] <= c) {
            v_res[depth] = 1;
            sum_now += S[depth];
            backtrack(depth + 1);
            sum_now -= S[depth];
        }
        int temp = 0;
        for (int i = depth + 1; i < n; i++) {
            temp += S[i];
        }
        if (sum_now + temp >= c) {
            v_res[depth] = 0;
            backtrack(depth + 1);
        }
    }
}
void subset_sum_solute(int *S, int n, int c) {
    subset_sum x;
    x.solution_sum = 0;
    x.S = S;
    x.n = n;
    x.c = c;
    x.sum_now = 0;
    x.v_res = new int[n]{};
    x.backtrack(0);
    cout << endl;
    delete[] x.v_res;
}