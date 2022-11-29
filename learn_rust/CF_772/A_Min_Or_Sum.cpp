#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = 0, x;
        for (int i = 0; i < n; i++) cin >> x, ans |= x;
        cout << ans << '\n';
    }
}