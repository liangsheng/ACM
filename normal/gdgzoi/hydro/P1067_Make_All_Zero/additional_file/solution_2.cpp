#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n + 1), b(n + 1, n + 1), c(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] <= n && b[a[i]] == n + 1) b[a[i]] = i;
            if (a[i] <= n) c[a[i]]++;
        }
        // for (int i = 0; i <= n; i++) cout << "i= " << i << ", b[i]= " << b[i] << '\n';
        int ans = n, p = n, q, t = 0;
        for (int k = 1; k < n; k++) {
            q = min(p, b[k - 1] - 1);
            while (p > q) {
                t += (a[p] > k - 1);
                if (a[p] <= n) c[a[p]]--;
                p--;
            }
            ans = min(ans, k + t + p - c[k]);
            // cout << "k= " << k << ", p= " << p << ", t= " << t << ' ' << k + t + p - c[k] << '\n';
        }
        cout << ans << '\n';
    }
	return 0;
}

// 5 3 3 5 2 4 5 2 1
// 4 2 2 4 1 3 4 2 0  1