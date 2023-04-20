#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T, n;

bool gao(vector<LL> a, LL x) {
    LL now = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        now += a[i];
        if (now % x == 0) cnt++, now = 0;
    }
    return cnt > 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        LL sum = 0;
        vector<LL> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        vector<LL> b;
        bool f = 0;
        // sum = 200000000000000LL;
        for (LL i = 1; i * i <= sum; i++) {
            if (sum % i) continue;
            LL d = sum / i;
            if (gao(a, d)) {
                cout << d << '\n';
                f = 1;
                break;
            }
            // b.push_back(i);
            // if (sum / i != i) b.push_back(sum / i);
        }
        if (!f) cout << 1 << '\n';
        // cout << "size= " << b.size() << '\n';
        // sort(b.begin(), b.end());
        // for (int i = b.size() - 2; i >= 0; i--) if (gao(a, b[i])) {
        //     cout << b[i] << '\n';
        //     break;
        // }
    }
    return 0;
}