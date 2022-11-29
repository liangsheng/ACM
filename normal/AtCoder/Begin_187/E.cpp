#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))

typedef long long LL;

using namespace std;

const int N = 200005;

int n, m;
vector<pair<int, int> > e;
vector<int> g[N];

int now;
vector<int> a(N), f(N), L(N), R(N);
vector<LL> b(N), ans(N);

void dfs(int p, int fa) {
    L[p] = now, f[p] = fa;
    a[now] = p;
    for (auto &y: g[p]) {
        if (y == fa) continue;
        now++;
        dfs(y, p);
    }
    R[p] = now;
}

void add(int l, int r, int val) {
    for (int p = l; p <= n + 1; p += lowbit(p)) b[p] += val;
    for (int p = r + 1; p <= n + 1; p += lowbit(p)) b[p] -= val;
}

LL cal(int p) {
    LL ans = 0;
    for (; p > 0; p -= lowbit(p)) ans += b[p];
    return ans;
}

void init() {
    fill(a.begin(), a.end(), 0);
    fill(b.begin(), b.end(), 0);

    now = 1;
    dfs(1, -1);

    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    // puts("");
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ' ' << L[i] << ' ' << R[i] << '\n';
    // }
}

int main() {
    for (int i = 1; i <= 32; i++) {
        cout << i << ' ' << (i & (i ^ (i - 1))) << '\n';
    }
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, x, y, u, v;
    while (cin >> n) {
        e.clear();
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            e.push_back({x, y});
            g[x].push_back(y);
            g[y].push_back(x);
        }

        init();
        cin >> m;
        while (m--) {
            cin >> t >> x >> y;
            if (t == 1) {
                u = e[x - 1].first, v = e[x - 1].second;
            } else {
                u = e[x - 1].second, v = e[x - 1].first;
            }
            if (f[u] == v) add(L[u], R[u], y);
            else {
                add(L[1], R[1], y);
                add(L[v], R[v], -y);
            }
        }
        for (int i = 1; i <= n; i++) ans[a[i]] = cal(i);
        for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    }
    return 0;
}