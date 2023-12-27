#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    while (cin >> n >> q) {
        vector<LL> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) a[i] += a[i - 1];
        LL x;
        while (q--) {
            cin >> x;
            cout << upper_bound(a.begin(), a.end(), x) - a.begin() << '\n';
        }
    }
    return 0;
}