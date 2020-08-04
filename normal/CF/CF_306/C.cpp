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

string s;
int n;

int main() {
    int flag, ans;
    while (cin >> s) {
        n = s.size();
        flag = 0;
        rep (i, n) if (!flag) FOR (j, i + 1, n - 1) if (!flag) FOR (k, j + 1, n - 1) {
            ans = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
            if ((ans % 8) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "YES\n" << ans << '\n';
            continue;
        }
        rep (i, n) if (!flag) FOR (j, i + 1, n - 1) {
            ans = (s[i] - '0') * 10 + (s[j] - '0');
            if ((ans % 8) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "YES\n" << ans << '\n';
            continue;
        }
        rep (i, n) {
            ans = (s[i] - '0');
            if ((ans % 8) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "YES\n" << ans << '\n';
        } else cout << "NO\n";
    }
    return 0;
}














