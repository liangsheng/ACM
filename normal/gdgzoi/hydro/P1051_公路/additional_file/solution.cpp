#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, d;
    while (cin >> n >> d) {
        vector<int> v(n + 1, 0);
        vector<int> a(n + 1, 0);
        for (int i = 1; i < n; i++) cin >> v[i];
        for (int i = 1; i <= n; i++) cin >> a[i];

        int e = 0;
        vector<int> R(n + 2, -1);
        vector<int> q(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            while (e > 0 && a[i] < a[q[e - 1]]) {
                R[q[e - 1]] = i;
                e--;
            }
            q[e++] = i;
        }

        LL ans = 0;
        vector<LL> b(n + 1, 0);
        for (int i = 1; i <= n; i++) b[i] = b[i - 1] + v[i - 1];
        LL now = 0;
        for (int i = 1; i < n; ) {
            int p = (R[i] == -1 ? n : R[i]);
            LL tol = b[p] - b[i];
            if (now >= tol) now -= tol;
            else {
                tol -= now, now = 0;
                LL h = tol / d + (tol % d > 0);
                ans += h * a[i];
                now = h * d - tol;
            }
            i = p;
        }
        cout << ans << '\n';
    }
    return 0;
}