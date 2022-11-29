#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 10005;

int n, x;
int p[N];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) {
            cin >> x;
            p[i] -= x;
        }
        int ans = (p[1] > 0 ? p[1] : -p[1]);
        for (int i = 2; i <= n; i++) {
            if (p[i] == 0) continue;
            if (p[i] * p[i - 1] > 0) ans += max(0, abs(p[i]) - abs(p[i - 1]));
            else ans += abs(p[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}