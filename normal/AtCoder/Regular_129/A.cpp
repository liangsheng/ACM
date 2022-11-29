#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL INF = ~0ULL >> 1;

LL n, l, r;

LL gao(LL r) {
    LL a = 0, b = 0, c = 0, d = 1;
    LL w, x, y, z;
    for (int k = 60; k >= 0; k--) {
        int x = n >> k & 1;
        if (x) {
            w = a * 2 + b + c;
            x = b + d;
            y = c;
            z = 0;
        } else {
            w = a * 2;
            x = b;
            y = c;
            z = d;
        }
        a = w, b = x;
        c = y, d = z;
    }
    cout << "r= " << r << ' ' << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    return a + c;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout << INF << '\n' << "1000000000000000000" << '\n';
    // cout << (1LL << 60) << '\n';
    while (cin >> n >> l >> r) {
        cout << gao(r) - gao(l - 1) << '\n';
    }
    return 0;
}