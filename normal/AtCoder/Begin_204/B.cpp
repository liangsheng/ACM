#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, x, ans;
    while (cin >> n) {
        ans = 0;
        while (n--) {
            cin >> x;
            ans += x > 10 ? x - 10 : 0;
        }
        cout << ans << '\n';
    }
    return 0;
}