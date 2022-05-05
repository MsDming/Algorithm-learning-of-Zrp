#include <algorithm>
#include <iostream>
using namespace std;

class schedule {
    friend void JobSchedule(int *time, int n, int k);

  private:
    void Backtrack(int depth);
    int *machine, *time;
    int *x, *bestx;
    int n, k;
    int best_time, max_time_now;
};

void schedule::Backtrack(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++)
            bestx[i] = x[i];
        best_time = max_time_now;
        return;
    }
    for (int i = 1; i <= k; i++) {
        x[depth] = i;
        machine[i - 1] += time[depth];
        max_time_now = *max_element(machine, machine + 3);
        if (max_time_now < best_time)
            Backtrack(depth + 1);
        machine[i - 1] -= time[depth];
    }
}

void JobSchedule(int *time, int n, int k) {
    schedule S;
    S.n = n;
    S.k = k;
    S.time = time;
    S.x = new int[n]{};
    S.bestx = new int[n]{};
    S.machine = new int[k]{};
    S.best_time = 9999;
    S.Backtrack(0);
    cout << "最佳调度：";
    for (int i = 0; i < n; i++)
        cout << S.bestx[i] << "  ";
    cout << "\n最短时间：" << S.best_time << endl;
    delete[] S.x, S.bestx, S.machine;
}

int main() {
    int n1 = 7, k1 = 3, t1[7] = {2, 14, 4, 16, 6, 5, 3};
    cout << "n=7,  k=3, t[7]={  2, 14, 4, 16, 6, 5, 3 } 时" << endl;
    JobSchedule(t1, n1, k1);
    cout << endl;
    int n2 = 10, k2 = 3, t2[10] = {1, 7, 4, 0, 9, 4, 8, 8, 2, 4};
    cout << "n=10, k=3, t[10]={ 1, 7, 4, 0, 9, 4, 8, 8, 2, 4 } 时" << endl;
    JobSchedule(t2, n2, k2);
    system("pause");
    return 0;
}
