#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s;
    while (cin >> n >> m) {
        cin >> s;

        int x = 0, y = 0;
        for (int i = 0; i < n; i++) x += (s[i] == 'X');
        y = n - x;
        if (x == n) {
            if (m == 0) cout << 0 << '\n';
            else cout << m - 1 << '\n';
            continue;
        }
        if (m <= x) {
            vector<pair<int, int>> a;
            for (int i = 0; i < n; i++) if (s[i] == 'X') {
                int j = i;
                while (i + 1 < n && s[i + 1] == 'X') i++;
                a.push_back({j, i});
            }
            sort(a.begin(), a.end(), [&](const pii& p, const pii& q) {
                return p.Y - p.X + 1 < q.Y - q.X + 1;
            });
            // for (int i = 0; i < a.size(); i++) {
            //     if (a[i].X == 0 || a[i].Y == n - 1) continue;
            //     cout << a[i].X << ' ' << a[i].Y << '\n';
            // }
            for (int i = 0; i < a.size(); i++) {
                if (a[i].X == 0 || a[i].Y == n - 1) continue;
                for (int j = a[i].X; m > 0 && j <= a[i].Y; j++, m--) s[j] = 'Y';
                if (m <= 0) break;
            }
            if (m > 0) {
                int l, r;
                for (int i = 0; i < n; i++) if (s[i] == 'Y') {
                    l = i;
                    break;
                }
                for (int i = n - 1; i >= 0; i--) if (s[i] == 'Y') {
                    r = i;
                    break;
                }
                for (int i = l - 1; m > 0, i >= 0; i--, m++) s[i] = 'Y';
                for (int i = r + 1; m > 0, i < n; i++, m++) s[i] = 'Y';
            }
        } else {
            m -= x;
            string t = s;
            int p = 0;
            while (t[p] == 'Y' && m > 0) {
                t[p] = 'X', m--;
                if (++p == n) break;
            }
            p = n - 1;
            while (t[p] == 'Y' && m > 0) {
                t[p] = 'X', m--;
                if (--p < 0) break;
            }
            if (m > 0) {
                vector<pair<int, int>> a;
                for (int i = 0; i < n; i++) if (t[i] == 'Y') {
                    int j = i;
                    while (i + 1 < n && t[i + 1] == 'Y') i++;
                    a.push_back({j, i});
                }
                sort(a.begin(), a.end(), [&](const pii& p, const pii& q) {
                    return p.Y - p.X + 1 > q.Y - q.X + 1;
                });
                for (int i = 0; i < a.size(); i++) {
                    for (int j = a[i].X; m > 0 && j <= a[i].Y; j++, m--) t[j] = 'X';
                    if (m <= 0) break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (s[i] == 'X') s[i] = 'Y';
                else if (t[i] == 'X') s[i] = 'X';
            }
        }
        // cout << "s= " << s << '\n';
        int ans = 0;
        for (int i = 0; i < n; i++) if (s[i] == 'Y') {
            int j = i;
            while (i + 1 < n && s[i + 1] == 'Y') i++;
            ans += i - j;
        }
        cout << ans << '\n';
    }
    return 0;
}