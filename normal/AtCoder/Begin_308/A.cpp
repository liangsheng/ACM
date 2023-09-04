// 有限小数
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    LL p, q, d;
    cin >> T;
    while (T--) {
        cin >> p >> q >> d;
        LL t = __gcd(p, q);
        p /= t, q /= t;
        t = __gcd(q, d);
        while (t != 1) {
            q /= t;
            t = __gcd(t, q);
        }
        if (q == 1) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}