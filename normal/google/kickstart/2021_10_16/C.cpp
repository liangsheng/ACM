#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 5005;

int T, n;
LL a[N], b[N], k;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int cas = 0, ans;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        b[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = b[i - 1] + a[i]; 
        }
        vector<int> q(k + 1, -1);
        q[0] = 0, ans = -1;
        if (a[n] <= k) q[a[n]] = 1;
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                LL d = b[i] - b[j - 1], t = i - j + 1;
                if (k - d >= 0 && q[k - d] != -1) {
                    if (ans == -1 || t + q[k - d] < ans) ans = t + q[k - d];
                }
            }
            for (int j = i; j <= n; j++) {
                LL d = b[j] - b[i - 1], t = j - i + 1;
                if (d <= k && (q[d] == -1 || q[d] > t)) q[d] = t;
            }
        }
        if (q[k] != -1) if (ans == -1 || q[k] < ans) ans = q[k];
        cout << "Case #" << ++cas << ": " << ans << '\n';
    }
    return 0;
}