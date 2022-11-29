#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, d, l, r;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        l = 0, r = n - 1, d = 0;
        while (l != r) {
            // cout << "l= " << l << " " << r << ' ' << d << '\n';
            if (a[r] == d) r--;
            else if (a[l] == d) l++, d = 1 - d;
            else break;
        }
        if (l != r || a[l] != d) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }
    return 0;
}