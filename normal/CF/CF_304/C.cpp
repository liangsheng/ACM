#include <bits/stdc++.h>

#define file_r(x) freopen(x, stdin, "r")
#define file_w(x) freopen(x, stdout, "w")
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh

#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define be begin
#define nb rbegin
#define er erase
#define SZ(c) c.size()

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 15;

int n, k1, k2;
int a[N], b[N];
string s1, s2;
set<string> s;

int main() {
    int ans, x, y, sz1, sz2;
    //cout << 24 * 30 * 56 * 90 * 10;
    while (cin >> n) {
        s1.clear();
        cin >> k1;
        rep (i, k1) cin >> a[i], s1.pb(a[i] + '0');
        s2.clear();
        cin >> k2;
        rep (i, k2) cin >> b[i], s2.pb(b[i] + '0');
        s.clear();
        s.insert(s1 + "a" + s2);
        //cout << s1 + "a" + s2 << '\n';
        ans = 0;
        while (1) {
            sz1 = SZ(s1), sz2 = SZ(s2);
            if (sz1 == 0) break;
            if (sz2 == 0) break;
            x = s1[0] - '0', y = s2[0] - '0';
            if (x > y) s1 = s1.substr(1, sz1 - 1) + char('0' + y) + char('0' + x), s2 = s2.substr(1, sz2 - 1);
            else s2 = s2.substr(1, sz2 - 1) + char('0' + x) + char('0' + y), s1 = s1.substr(1, sz1 - 1);
            ans++;
            if (s.count(s1 + "a" + s2)) {
                ans = -1;
                break;
            }
            //cout << s1 + "a" + s2, system("pause");
            s.insert(s1 + "a" + s2);
        }
        if (ans == -1) cout << ans << '\n';
        else {
            if (sz1 == 0) cout << ans << ' ' << 2 << '\n';
            else cout << ans << ' ' << 1 << '\n';
        }
    }
    return 0;
}




















