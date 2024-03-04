#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int P = 107, MOD = 998244353;

/*------------------------------- 字符串 hash begin ------------------------*/

int n;
vector<int> L, R, d;

void init(string& s) {
    n = s.size();
    d = vector<int>(n, 1);
    for (int i = 1; i < n; i++) d[i] = (LL) d[i - 1] * P % MOD;

    L = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        L[i] = (L[i - 1] + (LL) d[i - 1] * (s[i - 1] - 'a')) % MOD;
    }

    R = vector<int>(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        R[i] = (R[i + 1] + (LL) d[n - i] * (s[i - 1] - 'a')) % MOD;
    }
}

bool ok(int i, int j) {
    int x = ((LL) d[n - j] * (L[j] - L[i - 1]) % MOD + MOD) % MOD;
    int y = ((LL) d[i - 1] * (R[i] - R[j + 1]) % MOD + MOD) % MOD; 
    return x == y;
}
/*------------------------------- 字符串 hash end --------------------------*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    string s;
    cin >> s;
    init(s);
    LL ans = 0;
    for (int l = 1; l <= n; l++) {
        vector<int> a(26, 0);
        for (int r = l; r <= n; r++) {
            if (++a[s[r - 1] - 'a'] > 2) break;
            ans += ok(l, r);
        }
    }
    cout << ans << '\n';
    return 0;
}