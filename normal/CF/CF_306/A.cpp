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

int main() {
    string s;
    int l, r, n;
    while (cin >> s) {
        n = s.size();

        l = -1, r = -1;
        rep (i, n - 1) if (s[i] == 'A' && s[i + 1] == 'B') {
            l = i;
            break;
        }
        FORD (i, n - 1, 1) if (s[i] == 'A' && s[i - 1] == 'B') {
            r = i - 1;
            break;
        }
        if (l !=-1 && r != -1 && r >= l + 2) cout << "YES" << '\n';
        else {
            l = -1, r = -1;
            rep (i, n - 1) if (s[i] == 'B' && s[i + 1] == 'A') {
                l = i;
                break;
            }
            FORD (i, n - 1, 1) if (s[i] == 'B' && s[i - 1] == 'A') {
                r = i - 1;
                break;
            }
            if (l != -1 && r != -1 && r >= l + 2) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}













