#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int n, e;
int a[N], L[N], R[N], h[N];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        e = 0;
        for (int i = 1; i <= n; i++) {
            while (e > 0 && a[i] < a[h[e - 1]]) R[h[--e]] = i;
            h[e++] = i;
        }
        while (e > 0) R[h[--e]] = n + 1;
        // for (int i = 1; i <= n; i++) cout << R[i] << ' ';
        // puts("");

        e = 0;
        for (int i = n; i >= 1; i--) {
            while (e > 0 && a[i] < a[h[e - 1]]) L[h[--e]] = i;
            h[e++] = i;
        }
        while (e > 0) L[h[--e]] = 0;

        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, a[i] * (R[i] - L[i] - 1));
        cout << ans << '\n';
    }
    return 0;
}