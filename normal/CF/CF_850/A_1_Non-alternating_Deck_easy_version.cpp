#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<vector<int>> a(2, vector<int>(2, 0));
        a[0][0]++;
        int p = 1, f = 1, cnt = 0, now = 2;
        while (p < n) {
            if (p + now >= n) {
                for (int i = p; i < n; i++) a[f][i % 2]++;
                break;
            } else {
                for (int i = p; i < p + now; i++) a[f][i % 2]++;
                p += now;
                now++;
            }
            if (++cnt == 2) f ^= 1, cnt = 0;
        }
        int one = 1;
        if (one) cout << a[0][0] + a[0][1] << ' ' << a[1][0] + a[1][1] << '\n';
        else  cout << a[0][0] << ' ' << a[0][1] << ' ' << a[1][0] << ' ' << a[1][1] << '\n';
    }
    return 0;
}