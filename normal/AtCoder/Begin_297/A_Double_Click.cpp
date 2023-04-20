#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = -1;
        for (int i = 0; i < n - 1; i++) if (a[i + 1] - a[i] <= m) {
            ans = a[i  + 1];
            break;
        }
        cout << ans << '\n';
    }
    return 0;
}