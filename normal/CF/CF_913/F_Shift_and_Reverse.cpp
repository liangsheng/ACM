#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

int gao(const vector<int>& a, int n, int d) {
    if (n == 1) return 0;
    vector<int> c(2 * n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i];
        c[i + n] = a[i];
    }

    int p = -1;
    vector<int> b(2 * n, 1);
    for (int i = 1; i < 2 * n; i++) {
        if (c[i] >= c[i - 1]) b[i] = b[i - 1] + 1;
        if (b[i] == n) p = i;
    }
    if (p == n - 1) return 0;
    if (p == -1) return INF;
    int l = p - n + 1, r = n - l;
    return min(r + d, 2 + l - d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = gao(a, n, 0);
        reverse(a.begin(), a.end());
        int res = gao(a, n, 1);
        ans = min(ans, res);
        if (ans == INF) ans = -1;
        cout << ans<< '\n';
    }
    return 0;
}