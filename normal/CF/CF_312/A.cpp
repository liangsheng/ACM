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

const int N = 105;

int n;
pair<int, int> p[N];

int main() {
    int c0, c1, ans, tmp, c;
    while (~scanf("%d", &n)) {
        rep (i, n) scanf("%d %d", &p[i].X, &p[i].Y);
        sort(p, p + n);
        c0 = 0;
        rep (i, n) {
            if (p[i].X < 0) c0++;
        }
        c1 = n - c0;
      //  sc2(c0, c1);
        if (c0 < c1) {
            ans = 0;
            rep (i, 2 * c0 + 1) ans += p[i].Y;
        } else if (c0 > c1) {
            ans = 0;
            FORD (i, n - 1, n - 2 * c1 - 1) ans += p[i].Y;
        } else {
            ans = 0;
            rep (i, n) ans += p[i].Y;
        }
        printf("%d\n", ans);
    }
    return 0;
}


















