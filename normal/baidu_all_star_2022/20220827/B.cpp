#include <bits/stdc++.h> 
using namespace std;
typedef long long LL;


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n + 1), ans(n + 1);
        set<pair<int, int>> s;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) s.insert({-a[i], i});
        for (int i = 1; i <= n; i++) {
            if (i + k <= n) s.insert({-a[i + k], i + k});
            auto it = s.begin();
            ans[i] = it->second;
            // printf("w= %d, p= %d\n", -it->first, it->second);
            s.erase(it);
        }
        LL res = 0;
        for (int i = 1; i <= n; i++) res += ((LL) (k + i) * (k + i) - (LL) ans[i] * ans[i]) * a[ans[i]];
        cout << res << '\n';
    }
    return 0;
}

// id, id + 1
// (id ^ 2 - x.first ^ 2) * x.second + ((id + 1) ^ 2 - y.first ^ 2) * y.second
// ((id + 1) ^ 2 - x.first ^ 2) * x.second + (id ^ 2 - y.first ^ 2) * y.second

// id ^ 2 * x.second + (id + 1) ^ 2 * y.second
// (id + 1) ^ 2 * x.second + id ^ 2 * y.second

// (2 * id + 1) * y.second
// (2 * id + 1) * x.second