#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        int p = 0;
        if (n % 2) p = 1;
        for (int i = p; i < n; i += 2) if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        bool flag = 1;
        for (int i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) {
            flag = 0;
            break;
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}