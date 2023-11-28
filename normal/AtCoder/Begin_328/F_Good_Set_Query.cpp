#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> f;
vector<LL> w;

void init(int n) {
    f = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) f[i] = i;
    w = vector<LL>(n + 1, 0);
}

int find(int x) {
    if (f[x] == x) return f[x];
    int fa = find(f[x]);
    w[x] = w[f[x]] + w[x];
    return f[x] = fa;
}

bool unit(int a, int b, LL d) {
    int fa = find(a), fb = find(b);
    if (fa == fb) return w[a] - w[b] == d;
    f[fa] = fb;
    w[fa] = w[b] + d - w[a];
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    LL d;
    while (cin >> n >> m) {
        vector<int> ans;
        init(n);
        for (int t = 1; t <= m; t++) {
            cin >> a >> b >> d;
            if (unit(a, b, d)) ans.push_back(t);
        }
        if (ans.size() > 0) {
            for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << ' ';
            cout << ans[ans.size() - 1] << '\n';
        } else cout << '\n';
    }
    return 0;
}