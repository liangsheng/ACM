#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

LL mypow(LL x, LL y) {
    LL res = 1;
    while (y) {
        if (y & 1) {
            res = res * x % MOD;
        }
        y >>= 1;
        x = x * x % MOD;
    }
    return res;
}

LL get(LL x) {
    return mypow(x, MOD - 2);
}

LL N, A, B, P, Q, D;
vector<vector<LL>> dp;

LL gao(LL A, LL B) {
    if (A >= N) return 1;
    if (B >= N) return 0;
    if (dp[A][B] != -1) return dp[A][B];
    LL tol = 0;
    for (int i = 1; i <= P; i++) for (int j = 1; j <= Q; j++) {
        LL c = gao(A + i, B + j);
        tol = (tol + c) % MOD;
    }
    dp[A][B] = tol * D % MOD;
    return dp[A][B];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while (cin >> N >> A >> B >> P >> Q) {
        D = get(P * Q);
        dp = vector<vector<LL>>(N + 1, vector<LL>(N + 1, -1));
        cout << gao(A, B) << '\n';
    }
    return 0;
}