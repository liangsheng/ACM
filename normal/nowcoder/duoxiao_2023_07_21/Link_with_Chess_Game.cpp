#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 10;

int n;

int ch(vector<int> a) {
    return a[0] * 100 + a[1] * 10 + a[2];
}

bool ok(vector<int> a, vector<int> f) {
    return a[0] >= 1 && a[0] <= n && a[1] >= 1 && a[1] <= n && a[2] >= 1 && a[2] <= n && !f[ch(a)];
}

bool gao(vector<int> a, vector<int> f) {
    // cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    int s = ch(a);
    f[s] = 1;
    for (int i = 0; i < 3; i++) for (int d = -1; d <= 1; d += 2) {
        a[i] += d;
        if (ok(a, f)) {
            f[ch(a)] = 1;
            if (!gao(a, f)) return 1;
            f[ch(a)] = 0;
        }
        a[i] -= d;
    }
    return 0;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    n = 3;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) {
        vector<int> a = {i, j, k};
        vector<int> f(1000, 0);
        cout << i << " " << j << " " << k << " " << gao(a, f) << '\n';
    }
    return 0;
}