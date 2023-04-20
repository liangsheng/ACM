#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int INF = ~0U >> 2;

int N, e;
vector<int> mp, id;
vector<int> p;

// jingly code
// https://codeforces.com/contest/1766/submission/184952734
void init() {
    for (int i = 2; i <= N; i++) {
        if (mp[i] == 0) mp[i] = i, id[i] = p.size(), p.push_back(i);
        for (int t : p) {
            if (i * t > N) break;
            mp[i * t] = t;
            if (i % t == 0) break;
        }
    }
    e = p.size();
    // cout << p.size() << '\n';
}

int n, s, t;
vector<int> a;
vector<vector<pii>> g;

void spfa() {
    queue<int> q;
    vector<bool> f(e + n, 0);
    vector<int> d(e + n, INF);
    vector<int> p(e + n, -1);
    f[s] = 1, d[s] = 0, p[s] = -1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop(), f[u] = 0;
        for (auto it : g[u]) {
            auto [v, w] = it;
            int t = d[u] + w;
            if (t < d[v]) {
                d[v] = t, p[v] = u;
                if (!f[v]) f[v] = 1, q.push(v);
            }
        }
    }
    if (d[t] == INF) cout << -1 << '\n';
    else {
        cout << d[t] + 1 << '\n';
        int now = t;
        vector<int> ans;
        while (now != s) {
            
            if (now >= e) ans.push_back(now - e + 1);
            // ans.push_back(now);
            now = p[now];
        }
        ans.push_back(s - e + 1);
        for (int i = ans.size() - 1; i > 0; i--) cout << ans[i] << ' ';
        cout << ans[0] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        a = vector<int>(n), N = 0;
        for (int i = 0; i < n; i++) cin >> a[i], N = max(N, a[i]);
        cin >> s >> t;
        if (s == t) {
            cout << 1 << '\n' << s << '\n';
            continue;
        }

        mp = vector<int>(N + 1, 0);
        id = vector<int>(N + 1, 0);
        init();
        g = vector<vector<pii>>(e + n, vector<pii>());
        for (int i = 0; i < n; i++) {
            int d = a[i];
            set<int> s;
            while (d != 1) s.insert(mp[d]), d /= mp[d];
            for (auto it : s) {
                int x = i + e, y = id[it];
                // cout << "x= " << x << ", y= " << y << '\n';
                g[x].push_back({y, 0});
                g[y].push_back({x, 1});
            }
        }
        s += e - 1, t += e - 1;
        // cout << "e= " << e << ", s= " << s << ", t= " << t << '\n';
        spfa();
    }
    return 0;
}