#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1000000, MOD = 1000000007;

vector<bool> mp(N + 1, 0);
vector<int> phi(N + 1);
// vector<int> p;

// jingly code
// https://codeforces.com/contest/1766/submission/184952734
void init() {
    for (int i = 2; i <= N; i++) phi[i] = i;
    for (int i = 2; i <= N; i++) if (mp[i] == 0) {
        // p.push_back(i);
        for (int j = i; j <= N; j += i) {
            mp[j] = 1;
            phi[j] = phi[j] / i * (i - 1); 
        }
    }
}

// int phi(int x) {
//     int ans = x;
//     while (x != 1) {
//         int d = mp[x];
//         ans = ans / d * (d - 1);
//         while (x % d == 0) x /= d;
//     }
//     return ans;
// }

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    init();
    // cout << phi[10] << '\n';
    LL n;
    cin >> n;
    for (int i = 1; i <= n; i++) printf("i= %d, %d\n", i, n / i);
    // if (n == 1) cout << 1 << '\n';
    // else if (n <= N) {
    //     LL ans = 0;
    //     for (int i = 2; i <= n; i++) {
    //         LL d = n / i;
    //         d = d * d % MOD * phi[i] % MOD;
    //         ans = (ans + d) % MOD;
    //     }
    //     ans = (ans * 2 % MOD + n * n % MOD) % MOD;
    //     cout << ans << '\n'; 
    // } else {
    //     cout << -1 << '\n';
    // }
    return 0;
}