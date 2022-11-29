#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<int> a(m + 1, 0), L(m + 1, 1), ans(m + 1, 1);
        for (int i = 1; i <= m; i++) cin >> a[i];
        L[0] = 1;
        for (int i = 1; i <= m; i++) {
            int x = a[i], y = a[i] + 1;
            if (x == L[i - 1]) L[i] = y;
            else if (y == L[i - 1]) L[i] = x;
            else L[i] = L[i - 1];
            // cout << "i= " << i << ", L[i]= " << L[i] << '\n';
        }
        ans[m] = L[m - 1];
        vector<int> c(n + 1, 0);
        for (int i = 1; i <= n; i++) c[i] = i;
        for (int k = m - 1; k >= 1; k--) {
            int x = a[k + 1], y = a[k + 1] + 1;
            swap(c[x], c[y]);
            // cout << "k= " << k << '\n';
            // for (int i = 1; i <= m; i++) cout << c[i] << ' ';
            // cout << '\n';
            ans[k] = c[L[k - 1]];
        }
        for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
    }
    return 0;
}