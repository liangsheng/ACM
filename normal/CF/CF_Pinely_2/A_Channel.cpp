#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, a, q;
    cin >> T;
    while (T--) {
        cin >> n >> a >> q;
        string s;
        cin >> s;
        int x = 0;
        for (int i = 0; i < q; i++) if (s[i] == '+') x++;
        if (x + a < n) {
            cout << "NO" << '\n';
            continue;
        }
        int maxi = a, now = a;
        for (int i = 0; i < q; i++) {
            if (s[i] == '+') now++;
            else now--;
            maxi = max(maxi, now);
        }
        if (maxi >= n) cout << "YES" << '\n';
        else cout << "MAYBE" << '\n';
    }
    return 0;
}