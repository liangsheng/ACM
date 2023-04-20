#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a, x, m;

LL power(LL x, LL y) {
    LL ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % m;
        x = x * x % m;
        y /= 2;
    }
    return ans;
}

LL gao(LL x) {
    if (x == 1) return 1 % m;
    LL ans = gao((x + 1) / 2);
    LL tmp = power(a, x / 2);
    if (x % 2 == 0) return ((ans + tmp * ans % m) % m + m) % m;
    return (((ans + tmp * ans % m) % m - tmp) % m + m) % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    while (cin >> a >> x >> m) cout << gao(x) << '\n';
    return 0;
}