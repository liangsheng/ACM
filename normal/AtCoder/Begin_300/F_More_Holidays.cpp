#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, m, k;
string s;

LL gao() {
    if (m >= 2) s = s + s, n = n + n;
    vector<LL> f(n + 1, 0);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + (s[i - 1] == 'x');
    LL ans = 0, p = 1;
    for (int i = 1; i <= n; i++) {
        while (p + 1 <= n && f[p + 1] - f[i - 1] <= k) p++;
        ans = max(ans, p - i + 1);
    }
    return ans;
}

LL hao() {
    vector<LL> R(n + 2, 0), L(n + 2, 0);
    for (int i = 1; i <= n; i++) L[i] = L[i - 1] + (s[i - 1] == 'x');
    for (int i = n; i >= 1; i--) R[i] = R[i + 1] + (s[i - 1] == 'x');
    LL c = 0;
    for (int i = 0; i < n; i++) c += (s[i] == 'x');
    LL ans = 0;
    for (LL d = k / c - 1; d <= k / c; d++) {
        LL D = min(d, m - 2);
        LL res = D * n, t = 0;
        LL h = k - D * c;
        if (h > 0) {
            int u = n + 1, v = 0;
            for (int i = 1; i <= n; i++) if (R[i] <= h) {
                u = i;
                break;
            }
            for (; u <= n + 1; u++) {
                while (v + 1 <= n && L[v + 1] + R[u] <= h) v++;
                t = max(t, n + 1 - u + v);
            }
            res += t;
        }
        ans = max(ans, res); 
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m >> k >> s) {
        int c = 0;
        for (int i = 0; i < n; i++) c += (s[i] == 'x');
        if (k < c || m <= 2) cout << gao() << '\n';
        else cout << hao() << '\n';
    }
    return 0;
}