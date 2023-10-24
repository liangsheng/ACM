#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = ~0U >> 2;

int n;
vector<LL> a;
vector<int> b, c, p, d, ans;
vector<vector<int>> g;

// 第 i 棵树, 从第 x 天种下, 到第 t 天有 多高
// max(b[i] + x * c[i], 1)
__int128 cal(int i, int x, int t) {
    if (c[i] >= 0) {
        return b[i] * (t - x + 1) + (__int128) c[i] * (x + t) * (t - x + 1) / 2;
    }
    if (x > p[i]) return t - x + 1;
    if (t <= p[i]) return b[i] * (t - x + 1) + (__int128) c[i] * (x + t) * (t - x + 1) / 2;
    return b[i] * (p[i] - x + 1) + (__int128) c[i] * (x + p[i]) * (p[i] - x + 1) / 2 + t - p[i];

    // __int128 tol = 0;
    // for (int j = x; j <= t; j++) {
    //     tol += max(b[i] + (LL) j * c[i], 1LL);
    // }
    // return tol;
}


// 第 i 棵树, 第 t 天打到至少 a[i], 最迟需要第几天种下
// max(b[i] + x * c[i], 1)
int gao(int i, int t) {
    // int ans = 0;

    // b[i] + c[i], b[i] + 2 * c[i], b[i] + 3 * c[i]
    // b[i] * (t - x + 1) + c[i] * (x + t) * (t - x + 1) / 2 >= a[i], 求最大 x
    // 2 * b[i] * (t - x + 1) + c[i] * (x + t) * (t - x + 1) >= 2 * a[i], 求最大 x
    // 设 d = t + 1
    // 2 * b[i] * (d - x) + c[i] * (d + x - 1) * (d - x) >= 2 * a[i]
    // 2 * b[i] * d - 2 * b[i] * x + c[i] * (d * d - x * x - d + x) >= 2 * a[i]
    // -c[i] * x * x + (c[i] - 2 * b[i]) * x + 2 * b[i] * d - c[i] * d + c[i] * d * d - 2 * a[i] >= 0
    
    __int128 tol = cal(i, 1, t);
    if (tol < a[i]) return -1;
    int l = 1, r = t, mid;
    while (l != r) {
        mid = (l + r) / 2 + 1;
        if (cal(i, mid, t) >= a[i]) l = mid;
        else r = mid - 1;
    }
    return l;

    // LL tol = 0;
    // for (int j = t; j >= 1; j--) {
    //     tol += max(b[i] + (LL) j * c[i], 1LL);
    //     if (tol >= a[i]) return j;
    // }
    return -1;
}

void dfs(int u, int fa) {
    for (int v : g[u]) if (v != fa) {
        dfs(v, u);
        d[u] = min(d[u], d[v] - 1);
    }
}

bool ok(int mid) {
    // cout << "mid= " << mid << '\n';
    for (int i = 1; i <= n; i++) {
        d[i] = gao(i, mid);
        // cout << "i= " << i << " " << d[i] << '\n';
        if (d[i] == -1) return false;
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; i++) cout << "nd_i= " << i << " " << d[i] << '\n';
    priority_queue<pair<int, int>> q;
    int now = 1;
    q.push({-d[1], 1});
    ans = vector<int>(n + 1, -1);
    while (!q.empty()) {
        auto [w, u] = q.top();
        // cout << u << '\n';
        q.pop(), w = -w;
        ans[u] = now++;
        if (ans[u] > d[u]) return false;
        for (int v : g[u]) if (ans[v] == -1) {
            q.push({-d[v], v});
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    while (cin >> n) {
        a = vector<LL>(n + 1, 0);
        b = vector<int>(n + 1, 0);
        c = vector<int>(n + 1, 0);
        g = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        p = vector<int>(n + 1, -1);
        d = vector<int>(n + 1, -1);
        for (int i = 1; i <= n; i++) if (c[i] < 0) {
            p[i] = b[i] / abs(c[i]) - (b[i] % abs(c[i]) == 0);
        }

        // for (int i = 1; i <= n; i++) {
        //     cout << "i= " << i << " " << (int) cal(i, 5, 10) << '\n';
        // }
        // int l = 1, r = 1000000000, mid, yes;
        int l = 1, r = 1000000000, mid, yes;
        while (l != r) {
            mid = (l + r) / 2;
            yes = ok(mid);
            // cout << "-------------yes= " << yes << '\n';
            if (yes) r = mid;
            else l = mid + 1;
        }

        cout << l << '\n';
    }
    return 0;
}