#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005, P = 10005;

int n, p;
string s;

template <typename T>
T extend_gcd(T a, T b, T &x, T&y) {
    T t, ret;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ret = extend_gcd(b, a % b, x, y);
        t = x;
        x = y;
        y = t - a / b * y;
        return ret;
    }
}

// ax = b(mod p)
int hao(LL a, LL b, LL p) {
    // cout << "FF " << a << ' ' << b << ' ' << p << '\n';
    LL d = __gcd(a, p);
    if (b % d) return -1;
    LL x, y;
    extend_gcd(a, p, x, y);
    return (x * b % p + p) % p;
}

LL gao() {
    LL ans = 0, a = 1, b = 0;
    if (p == 2 || p == 5) {
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') % p == 0) ans += i + 1;
        }
        return ans;
    }

    vector<int> dp(p, 0);
    dp[(s[0] - '0') % p] = 1, ans += dp[0];
    for (int i = 1; i < s.size(); i++) {
        int id = (s[i] - '0') % p;
        a = 10 * a % p, b = (10 * b + id) % p;
        dp[hao(a, (id - b + p) % p, p)]++;
        ans += dp[hao(a, p - b, p)];

        // printf("i= %d a= %lld b= %lld\n", i, a, b);
        // for (int j = 0; j < dp.size(); j++) printf("j= %d %d\n", j, dp[j]);
    }
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n >> p) {
        cin >> s;
        cout << gao() << '\n';
    }
    return 0;
}
