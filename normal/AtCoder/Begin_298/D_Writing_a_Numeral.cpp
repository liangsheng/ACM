#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 6000000, MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<LL> d(N + 1);
    d[1] = 1;
    for (int i = 2; i <= N; i++) d[i] = d[i - 1] * 10 % MOD;
    int n, cmd;
    while (cin >> n) {
        LL p = 1, ans = 1, x;
        queue<int> q;
        q.push(1);
        while (n--) {
            cin >> cmd;
            if (cmd == 3) cout << ans << '\n';
            else if (cmd == 1) {
                cin >> x;
                ans = (ans * 10 + x) % MOD, p++;
                q.push(x);
            } else {
                x = q.front(), q.pop();
                ans = ((ans - x * d[p]) % MOD + MOD) % MOD;
                p--;
            }
        }
    }
    return 0;
}