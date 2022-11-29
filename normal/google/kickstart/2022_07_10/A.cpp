#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n, m, cas = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        double ans = 0;
        for (int i = n - m + 1; i < n; i++) ans += a[i];
        if ((n - m + 1) % 2) ans += a[(n - m + 2) / 2 - 1];
        else ans += (a[(n - m + 1) / 2 - 1] + a[(n - m + 1) / 2]) / 2.0;
        printf("Case #%d: %.6f\n", ++cas, ans);
    }
    return 0;
}