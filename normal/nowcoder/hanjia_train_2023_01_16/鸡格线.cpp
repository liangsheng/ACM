#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int D = 11;

int n, m;
vector<vector<LL>> a;
vector<int> f, cnt;
LL ans;

int find(int x) {
    if (f[x] == x) return f[x];
    f[x] = find(f[x]);
    return f[x];
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n >> m) {
        ans = 0;
        a = vector<vector<LL>>(D + 1, vector<LL>(n + 1));
        for (int i = 1; i <= n; i++) cin >> a[0][i], ans += a[0][i];
        for (int i = 1; i <= D; i++) for (int j = 1; j <= n; j++) {
            a[i][j] = round(sqrt(a[i - 1][j]) * 10);
        }
        // for (int i = 1; i <= n; i++) cout << a[2][i] << ' ';
        // cout << '\n';

        f = vector<int>(n + 2, -1);
        for (int i = 0; i <= n + 1; i++) f[i] = i;
        cnt = vector<int>(n + 1, 0);
        int cmd, l, r, k;
        while (m--) {
            cin >> cmd;
            if (cmd == 2) cout << ans << '\n';
            else {
                cin >> l >> r >> k;
                int p = l;
                while (p <= r) {
                    // cout << "p= " << p << '\n';
                    if (cnt[p] != D) {
                        int t = min(D, cnt[p] + k);
                        ans = ans - a[cnt[p]][p] + a[t][p];
                        cnt[p] = t;
                        if (cnt[p] == D) f[p] = find(p + 1);
                    }
                    p = find(p + 1);
                }
            }
        }
    }
    return 0;
}