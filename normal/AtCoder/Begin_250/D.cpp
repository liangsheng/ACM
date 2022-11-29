#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1000000;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    vector<bool> f(N + 1, 0);
    vector<int> p;
    for (int i = 2; i <= N; i++) {
        if (f[i]) continue;
        p.push_back(i);
        for (LL j = (LL) i * i; j <= N; j += i) f[j] = 1;
    }
    int m = p.size();
    LL n;
    while (cin >> n) {
        LL ans = 0;
        for (int i = m - 1; i >= 0; i--) {
            LL d = n / p[i] / p[i] / p[i];
            int j = upper_bound(p.begin(), p.end(), d) - p.begin() - 1;
            j = min(j, i - 1);
            if (j >= 0) ans += j + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}