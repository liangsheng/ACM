#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, m;

LL gao() {
    if (m <= n) return m;
    LL p = floor(sqrt(m));
    if (p * p == m) {
        if (p <= n) return m;
        return -1;
    }
    if (p >= n) return -1;
    LL ans = ~0ULL >> 2, i;
    for (i = 2; i <= n && i * i <= m; i++) {
        if (i * n < m) continue;
        LL d = m / i;
        if (d * i < m) d++;
        if (d <= n) ans = min(ans, d * i); 
    } 
    ans = min(ans, i * i);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m) cout << gao() << '\n';
    return 0;
}