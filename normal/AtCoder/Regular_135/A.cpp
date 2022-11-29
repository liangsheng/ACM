#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 998244353;

map<LL, LL> ans;

LL dfs(LL x) {
    if (x <= 4) return x;
    if (ans.count(x)) return ans[x];
    LL d = dfs(x / 2);
    if (x % 2 == 0) return ans[x] = d * d % MOD;
    return ans[x] = d * dfs(x - x / 2) % MOD;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    LL x;
    while (cin >> x) {
        ans.clear();
        cout << dfs(x) << '\n';
    }
    return 0;   
}