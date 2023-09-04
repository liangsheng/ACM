#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool ok(LL x) {
    if (x <= 1) return 0;
    LL r = sqrt(x * 1.0) + 1;
    for (LL i = 2; i <= x && i < r; i++) if (x % i == 0) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // for (int i = 1; i <= 100; i++) if (ok(i)) cout << i << '\n';
    // int N = 97;
    // vector<int> b = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    // vector<int> c(N, 0);
    // for (int i = 0; i < b.size(); i++ ) for (int j = 0; j < b.size(); j++) {
    //     int t = b[i] + b[j];
    //     if (t < N) c[t] = 1;
    // }
    // for (int i = 4; i < N; i++) if (c[i] == 0) cout << i << '\n';
    // for (int i = 90; i <= 100; i++) cout << i << ' ' << ok(i) << '\n';
    // cout << ok(1) << '\n';
    int n;
    while (cin >> n) {
        vector<LL> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        LL ans = accumulate(a.begin(), a.end(), 0LL);
        if (ans < 2 * n) cout << "No" << '\n';
        else {
            if (n == 1) cout << (ok(a[0]) ? "Yes" : "No") << '\n';
            else if (n == 2) {
                if (ans & 1) cout << (ok(ans - 2) ? "Yes" : "No") << '\n';
                else cout << "Yes" << '\n';
            } else cout << "Yes" << '\n';
        }
    }
    return 0;
}