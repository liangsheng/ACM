#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> k(n + 1), h(n + 1), L(n + 1), p(n + 1);
        for (int i = 1; i <= n; i++) cin >> k[i];
        for (int i = 1; i <= n; i++) cin >> h[i];

        L[n] = k[n] - h[n] + 1, p[n] = n;
        for (int i = n - 1; i >= 1; i--) {
            if (k[i] - h[i] + 1 < L[i + 1]) L[i] = k[i] - h[i] + 1, p[i] = i;
            else L[i] = L[i + 1], p[i] = p[i + 1];
        }
        // for (int i = 1; i <= n; i++) {
        //     printf("i= %d, p[i]= %d, L[i]= %d\n", i, p[i], L[i]);
        // }
        LL ans = (1LL + h[p[1]]) * h[p[1]] / 2, nowp = p[1], nowh = h[p[1]];
        // cout << "ans= " << ans << " nowp= " << nowp << " nowh= " << nowh << '\n';
        for (int i = nowp + 1; i <= n; i++) {
            // cout << "i= " << i << " " << L[i] << " " << k[nowp] << '\n';
            if (L[i] <= k[nowp]) {
                int d = k[p[i]] - k[nowp];
                ans += (nowh + 1LL + nowh + d) * d / 2;
                nowp = p[i], nowh = nowh + d; 
            } else {
                ans += (1LL + h[p[i]]) * h[p[i]] / 2;
                nowp = p[i], nowh = h[p[i]];
            }
            i = p[i];
        }
        cout << ans << '\n';
    }
    return 0;
}