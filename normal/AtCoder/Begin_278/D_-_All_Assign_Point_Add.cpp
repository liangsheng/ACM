#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, t, p, v;
    while (cin >> n) {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        cin >> m;
        vector<vector<LL>> b(n + 1, vector<LL>());
        vector<vector<int>> c(n + 1, vector<int>());
        int nowp = -1, nowv;
        for (int i = 1; i <= m; i++) {
            cin >> t;
            if (t == 1) {
                cin >> v;
                nowp = i, nowv = v;
            } else if (t == 2) {
                cin >> p >> v;
                if (b[p].size() == 0) b[p].push_back(v);
                else b[p].push_back(*b[p].rbegin() + v);
                c[p].push_back(i);
            } else {
                cin >> p;
                if (nowp == -1) {
                    if (b[p].size() == 0) cout << a[p] << '\n';
                    else cout << a[p] + *b[p].rbegin() << '\n';
                } else {
                    if (b[p].size() == 0) cout << nowv << '\n';
                    else {
                        int id = lower_bound(c[p].begin(), c[p].end(), nowp) - c[p].begin();
                        // cout << "id= " << id << ' ' << c[p].size() << '\n';
                        if (id == c[p].size()) cout << nowv << '\n';
                        else if (id == 0) cout << *b[p].rbegin() + nowv << '\n';
                        else cout << *b[p].rbegin() - b[p][id - 1] + nowv << '\n';
                    }
                }
            }
        }
    }
    return 0;
}