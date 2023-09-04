#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m) {
        m *= m;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
        auto gao = [&](int i, int j) {
            return (a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]);
        };
        vector<int> f(n, 0);
        f[0] = 1;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < n; i++) if (!f[i] && gao(i, u) <= m) f[i] = 1, q.push(i);
        }
        for (int i = 0; i < n; i++) cout << (f[i] ? "Yes" : "No") << '\n';
    }
    return 0;
}