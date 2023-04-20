#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
vector<LL> c, d;

void init(int k, int s, int t) {
    if (s == t) d[k] = c[s - 1];
    else {
        int mid = (s + t) >> 1;
        init(k << 1, s, mid);
        init(k << 1 | 1, mid + 1, t);
        d[k] = max(d[k << 1], d[k << 1 | 1]);
    }
}

void build(vector<LL>& b) {
    n = b.size();
    c = b;
    d = vector<LL>(n * 4 + 1, 0);
    init(1, 1, n);
}

LL query(int k, int s, int t, int l, int r) {
    if (t < l || s > r) return 0;
    if (s >= l && t <= r) return d[k];
    int mid = (s + t) >> 1;
    LL ans = query(k << 1, s, mid, l, r);
    ans = max(ans, query(k << 1 | 1, mid + 1, t, l, r));
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL x, y, z;
    while (cin >> n) {
        map<LL, vector<LL>> f, k;
        map<LL, LL> w, h;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            w[x] += z;
            h[y] += z;
            f[y].push_back(x);
            k[y].push_back(z);
        }
        set<pair<LL, LL>> q;
        for (auto it : w) q.insert({it.second, it.first});

        LL ans = 0;
        for (auto it : f) {
            y = it.first;
            LL tmp = h[it.first];
            vector<LL> g = it.second, r = k[y];
            for (int i = 0; i < g.size(); i++) {
                x = g[i], z = r[i];
                q.erase({w[x], x});
                q.insert({w[x] - r[i], x});
            }
            tmp += (*q.rbegin()).first;
            ans = max(ans, tmp);
            for (int i = 0; i < g.size(); i++) {
                x = g[i], z = r[i];
                q.erase({w[x] - r[i], x});
                q.insert({w[x], x});
            }
        }
        cout << ans << '\n';
    }
    return 0;
}