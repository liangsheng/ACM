#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int p = 1;
        for (int i = 0; i < n; i++) if (a[i] == p) p++;
        p = n - (p - 1);
        cout << p / m + (p % m > 0) << '\n';
    }
    return 0;
}