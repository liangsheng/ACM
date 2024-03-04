#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 25;

int n;
int a[N];
vector<unordered_map<int, unordered_set<int>>> q(2);

void dfs(int p, int r, int s, int st, int id) {
    if (p == r) {
        if (st > 0 && s >= 0) q[id][s].insert(st);
        return ;
    }
    dfs(p + 1, r, s, st, id);
    dfs(p + 1, r, s + a[p], st | (1 << p), id);
    dfs(p + 1, r, s - a[p], st | (1 << p), id);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    while (cin >> n) {
        q[0].clear(), q[1].clear();
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;

        q[0].clear();
        dfs(0, n / 2, 0, 0, 0);
        if (q[0].count(0)) ans += q[0][0].size();
        // cout << "ans= " << ans << '\n';

        q[1].clear();
        dfs(n / 2, n, 0, 0, 1);
        if (q[1].count(0)) ans += q[1][0].size();
        // cout << "ans= " << ans << '\n';

        unordered_set<int> res;
        for (auto it : q[0]) if (q[1].count(it.first)) {
            for (int i: it.second) for (int j : q[1][it.first]) res.insert(i + j);
            // ans += it.second.size() * q[1][it.first].size();
            // cout << "it.first: " << it.first << " " << it.second.size() << " " << q[1][it.first].size() << '\n';
        }
        cout << ans + res.size() << '\n';
    }
    return 0; 
}