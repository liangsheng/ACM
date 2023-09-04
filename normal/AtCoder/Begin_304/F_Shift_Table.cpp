#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    while (cin >> n >> s) {
        vector<int> t(n + 1);
        t[0] = 1;
        for (int i = 1; i <= n; i++) t[i] = (LL) t[i - 1] * 2 % MOD;

        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = (s[i] == '#');
        
        vector<int> p;
        for (int i = 1; i < n; i++) if (n % i == 0) p.push_back(i);
        int ans = 0;
        int m = p.size();
        for (int st = 1; st < (1 << m); st++) {
            int f = -1, d = -1, sz = 0;
            for (int i = 0; i < m; i++) if ((st >> i) & 1) {
                f = 0 - f, sz++;
                if (d == -1) d = p[i];
                else d = __gcd(d, p[i]);
            }
            vector<int> b(d, 1);
            for (int i = 0; i < n; i++) b[i % d] &= a[i];
            int cnt = accumulate(b.begin(), b.end(), 0);
            // cout << "st= " << st << ", d = " << d << " " << t[cnt] << ", sz= " << sz << ", f= " << f << '\n'; 
            ans = (ans + (LL) f * t[cnt]) % MOD;
        }

        cout << ans << '\n';
    }
    return 0;
}