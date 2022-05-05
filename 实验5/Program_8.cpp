#include <cmath>
#include <iostream>
using namespace std;

class Circle {
    friend float CirclePerm(int n, float *a);

  private:
    float Center(int t);
    void Compute();
    void Backtrack(int t);
    float min, *x, *r, *bestr;
    int n;
};

float Circle::Center(int t) { /*计算当前所选圆的圆心坐标*/
    float temp = 0;
    for (int j = 1; j < t; j++) {
        float value = x[j] + 2.0 * sqrt(r[t] * r[j]);
        if (value > temp)
            temp = value;
    }
    return temp;
}

void Circle::Compute() {
    float low = 0, high = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] - r[i] < low)
            low = x[i] - r[i];
        if (x[i] + r[i] > high)
            high = x[i] + r[i];
    }
    if (high - low < min) {
        min = high - low;
        for (int i = 0; i < n; i++)
            bestr[i] = r[i + 1];
    }
}

void Circle::Backtrack(int t) {
    if (t > n) {
        Compute();
        return;
    }
    for (int j = t; j <= n; j++) {
        swap(r[t], r[j]);
        float centerx = Center(t);
        if (centerx + r[t] + r[j] < min) {
            x[t] = centerx;
            Backtrack(t + 1);
        }
        swap(r[t], r[j]);
    }
}

float CirclePerm(int n, float *a) {
    Circle C;
    C.n = n;
    C.r = a;
    C.min = 9999;
    C.x = new float[n + 1]{};
    C.bestr = new float[n]{};
    C.Backtrack(1);
    cout << "符合条件的圆排列：";
    for (int i = 0; i < n; i++)
        cout << C.bestr[i] << "  ";
    cout << endl;
    delete[] C.x;
    return C.min;
}

int main() {
    int n = 3;
    float x[4] = {0, 1, 1, 2};
    int res = CirclePerm(n, x);
    cout << "最小长度：" << res << endl;
    system("pause");
    return 0;
}