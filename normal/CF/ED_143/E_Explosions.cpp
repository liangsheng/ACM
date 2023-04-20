#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<LL> a(n + 1, 0);
        vector<LL> b(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = b[i - 1] + a[i];
        }
        vector<int> L(n + 1, 0), R(n + 1, 0);
        L[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i - 1] <= a[i] - 1) L[i] = L[i - 1];
            else L[i] = i;
        }
        R[n] = n;
        for (int i = n - 1; i >= 1; i--) {
            if (a[i + 1] <= a[i] - 1) R[i] = R[i + 1];
            else R[i] = i;
        }
        for (int i = 1; i <= n; i++) cout << L[i] << ' ' << R[i] << '\n';;
        cout << '\n';
        // for (int i = 1; i <= n; i++) cout << R[i] << ' ';
        // cout << '\n';
        LL ans = accumulate(a.begin(), a.end(), 0LL);
        for (int i = 1; i <= n; i++) {
            LL tmp = a[i];
            int l = L[i], r = R[i];
            if (l != 1) tmp += b[l - 1];
            if (r != n) tmp += b[n] - b[r];
            ans = min(ans, tmp);
            cout << "i= " << i << ' ' << tmp << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}