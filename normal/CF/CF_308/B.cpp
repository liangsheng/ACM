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

LL n;
LL a[100], b[100];

int main() {
    a[0] = 1;
    a[1] = 10, b[1] = 9;
    FOR (i, 2, 9) {
        a[i] = a[i - 1] * 10;
        b[i] = b[i - 1] + (a[i] - a[i - 1]) * i;
    }
    LL ans, p;
    //sc2(b[1], b[2]);
    while (cin >> n) {
        ans = 0, p = 0;
        FOR (i, 1, 9) {
            if (n >= a[i]) ans = b[i], p = i;
            else break;
        }
        //sc2(p, ans);
        ans += (n - a[p] + 1) * (p + 1);
        cout << ans << '\n';
    }
    return 0;
}

















