#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> g(n), s(n), b(n);
    for (int i = 0; i < n; i++) cin >> g[i] >> s[i] >> b[i];

    auto gao = [&](vector<int>& a) {
        vector<int> c;
        for (int x : a) c.push_back(x);
        sort(c.begin(), c.end());
        // 这里要写完全, 不能写 c.erase(unique(c.begin(), c.end())); 会 RE !!
        c.erase(unique(c.begin(), c.end()), c.end());

        int m = c.size();
        vector<int> d(m + 2, 0);
        for (int i = 0; i < (int) a.size(); i++) {
            a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
            d[a[i]]++;
        }
        for (int i = m - 1; i >= 1; i--) d[i] += d[i + 1];
        return d; 
    };

    vector<int> dg = gao(g);
    vector<int> ds = gao(s);
    vector<int> db = gao(b);
    
    for (int i = 0; i < n; i++) {
        cout << min(min(dg[g[i] + 1], ds[s[i] + 1]), db[b[i] + 1]) + 1 << '\n';
    }
    return 0;
}