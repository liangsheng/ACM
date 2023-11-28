#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = a[0], now = a[0];
    for (int i = 1; i < n; i++) {
        now = max(a[i], a[i] + now);
        ans = max(ans, now);
    }
    cout << ans << '\n';
    return 0;
}