#include <bits/stdc++.h>
using namespace std;

bool gao(int n, vector<vector<int>>& g, vector<int> cnt) {
    int m = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) if (cnt[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        // cout << "u= " << u << '\n';
        q.pop(), m++;
        for (int v : g[u]) if (--cnt[v] == 0) q.push(v);
    }
    return m == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, e = 0;
    map<string, int> q;
    cin >> n;
    vector<vector<int>> g(2 * n, vector<int>());
    vector<int> cnt(2 * n, 0);
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (!q.count(a)) q[a] = e++;
        if (!q.count(b)) q[b] = e++;
        int x = q[a], y = q[b];
        g[x].push_back(y);
        cnt[y]++;
    }
    if (gao(e, g, cnt)) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}