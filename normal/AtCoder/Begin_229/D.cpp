#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
string s;

int gao() {
    int ans = 0, p, d = 0;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            ans = max(ans, d);
            d = 0;
        } else d++;
    }
    ans = max(ans, d);
    // cout << "ans= " << ans << '\n';
    if (m == 0) return ans;
    for (p = 0, d = 0; p < n; p++) {
        if (s[p] == 'X') continue;
        if (++d > m) break;
    }
    p--;
    ans = max(ans, p + 1);
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'X') continue;
        d = 0;
        while (p + 1 < n) {
            if (s[p + 1] == 'X') {
                p++;
                continue;
            } 
            if (++d > 1) break;
            p++;
            // cout << "p= " << p << " d= " << d << '\n';
        }
        ans = max(ans, p - i + 1);
        // cout << "i= " << i << ' ' << p << ' ' << ans << '\n';
    }
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> s >> m) cout << gao() << '\n';
    return 0;
}