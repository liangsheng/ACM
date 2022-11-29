#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int T, n, m;
int a[N], b[N], c[N], ans[N];
map<int, queue<int> > q;
map<int, queue<int> > f;

bool gao() {
    for (int i = m; i >= 1; i--) {
        bool hq = q.count(c[i]), hf = f.count(c[i]);
        if (!hq && !hf) {
            if (i == m) return 0;
            ans[i] = ans[i + 1];
        } else {
            if (hq) {
                ans[i] = q[c[i]].front(), a[ans[i]] = c[i];
                if (q[c[i]].size() > 1) q[c[i]].pop();
            } else {
                ans[i] = f[c[i]].front();
                a[ans[i]] = c[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) if (a[i] != b[i]) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        q.clear(), f.clear();
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (a[i] != b[i]) q[b[i]].push(i);
            else f[b[i]].push(i);
        }
        for (int i = 1; i <= m; i++) cin >> c[i];
        bool flag = gao();
        if (!flag) cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            for (int i = 1; i < m; i++) cout << ans[i] << ' ';
            cout << ans[m] << '\n';
        }
    }
    return 0;
}