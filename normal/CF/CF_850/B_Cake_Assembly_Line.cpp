#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, w, h;
    cin >> T;
    while (T--) {
        cin >> n >> w >> h;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int p = b[0] - h, L = 2 * w - 2 * h, f = 1;
        for (int i = 1; i < n; i++) {
            int l = a[i] - a[0] + p;
            int r = l + 2 * w;
            int s = b[i] - h, t = b[i] + h;
            if (s >= l && t <= r) {
                L = min(L, r - t);
                continue;
            }
            if (t > r) {
                f = 0;
                break;
            }
            if (l - s <= L) {
                L -= l - s;
                p -= l - s;
            } else {
                f = 0;
                break;
            }
        }
        cout << (f ? "YES" : "NO") << '\n';
    }
    return 0;
}