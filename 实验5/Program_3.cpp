#include <iostream>
using namespace std;
class n_queen_solution {
    friend void n_queen_solute(int n);

  private:
    int n;
    int *j_order;
    int **chessboard;

  public:
    void backtrack(int i);
    bool same_oblique_line(int i, int j);
};
void n_queen_solute(int n);
void output(int **chessboard, int n);
int main() {
    n_queen_solute(4);
    system("pause");
    return 0;
}
void n_queen_solution::backtrack(int i) {
    if (i == n) {
        for (int c = 0; c < n; c++) {
            chessboard[c][j_order[c]] = 1;
            cout << j_order[c] << "  ";
        }
        cout << ":" << endl << endl;
        output(chessboard, n);
    } else {
        for (int j = i; j < n; j++) {
            swap(j_order[i], j_order[j]);
            if (!same_oblique_line(i, j_order[i])) {
                backtrack(i + 1);
            }
            swap(j_order[i], j_order[j]);
        }
    }
}
bool n_queen_solution::same_oblique_line(int i, int j) {
    for (int k = 0; k < i; k++) {
        if ((i - k) == (j_order[i] - j_order[k]) ||
            (i - k) == (j_order[k] - j_order[i])) {
            return true;
        }
    }
    return false;
}
void n_queen_solute(int n) {
    n_queen_solution x;
    x.n = n;
    x.j_order = new int[n];
    x.chessboard = new int *[n];
    for (int i = 0; i < n; i++) {
        x.j_order[i] = i;
        x.chessboard[i] = new int[n]{};
    }
    x.backtrack(0);
    for (int i = 0; i < n; i++) {
        delete[] x.chessboard[i];
    }
    delete[] x.j_order;
    delete[] x.chessboard;
}
void output(int **chessboard, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << chessboard[i][j] << "  ";
            chessboard[i][j] = 0;
        }
        cout << endl << endl;
    }
    cout << endl << endl;
}