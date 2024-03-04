#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int D = 30, INF = 1000000000;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, k, q, x, t;
    cin >> n >> k >> q;
    vector<int> a(n + 1);
    vector<LL> b(n + 1, 0);
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) b[i] = b[i - 1] + a[i - 1];
    while (q--) {
        cin >> x >> t;
        if (t <= b[x]) cout << b[x] - t << '\n';
        else {
            LL c = (t - b[x]) / k;
            LL l = b[x] + c * k, r = l + k;
            if (t == l) cout << 0 << '\n';
            else cout << r - t << '\n';
        }
    }
    return 0;
}