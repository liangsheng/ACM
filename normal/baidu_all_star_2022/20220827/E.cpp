#include <bits/stdc++.h> 
using namespace std;
typedef long long LL;

LL H, ans;
LL a[11];
vector<LL> D = {0, 1, 2, 3, 6, 10, 15, 21, 28, 36, 45};

void gao(LL p, LL now) {
    // cout << "p= " << p << ", now= " << now << '\n';
    if (p == 0) {
        ans = max(ans, now);
        return ;
    }
    LL d = (H - now) / p;
    for (LL i = min(d, a[p]); i >= max(0LL, d - D[p]); i--) {
        gao(p - 1, now + i * p);
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> H) {
        for (int i = 1; i <= 10; i++) cin >> a[i];
        ans = 0;
        gao(10, 0);
        cout << ans << '\n';
    }
    return 0;
}