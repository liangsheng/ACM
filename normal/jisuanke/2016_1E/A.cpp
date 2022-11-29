#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
double l;

double cal(double x, int f) {
    if (f == 0) return x * n - x / 2;
    return x * n - x;
}

int main() {
    double ans, pi = acos(-1), ai;
    cin >> n >> k >> l;
    ans = 0;
    ai = pi - 2 * pi / n;
    for (int i = 0; i < k; i++) {
        ans += cal(l, 0);
        l = l / 2 * sin(ai / 2) * 2;
    }
    //cout << ans << ' ' << l << '\n';
    ans += cal(l, 1);
    printf("%.6f\n", ans);
    return 0;
}
