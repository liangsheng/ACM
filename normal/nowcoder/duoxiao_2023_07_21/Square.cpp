#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL INF = 1e18;

LL gao(LL n) {
    LL L = n, R = n, d = 1, t = 0;
    while (R <= INF) {
        LL l = floor(sqrt(L)), r = ceil(sqrt(R));
        for (LL x = l; x <= r; x++) {
            // cout << "x= " << x << '\n';
            if (x * x / d == n) return x;
        }
        L = L * 10, R = R * 10 + 9, d *= 10;
        if (++t >= 30) break;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << gao(n) << '\n';
    }
    return 0;
}