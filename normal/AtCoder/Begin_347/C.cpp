#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n, a, b;
    cin >> n >> a >> b;
    vector<LL> d(n);
    for (int i = 0; i < n; i++) cin >> d[i], d[i]--;

    LL l = 0, r = a - 1, now = 0, m = a + b;
    for (int i = 1; i < n; i++) {
        now = l - d[0] + d[i];
        LL nxt = (now + m - 1) / m * m;
        if (now % m < a) {
            if (now % m > 0) r = min(r, l + nxt - b - 1 - now);
        } else {
            l += nxt - now;
        }
        if (l > r) break;
    }
    cout << (l <= r ? "Yes" : "No") << '\n';
    return 0;
}