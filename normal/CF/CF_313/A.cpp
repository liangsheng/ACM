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
#define sqr(x) ((x) * (x))

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

int a[6];

int main() {
    while (~scanf("%d", &a[0])) {
        FOR (i, 1, 5) scanf("%d", &a[i]);
        int ans = a[0] * a[1] + a[2] * a[3] + a[4] * a[5];// + a[0] * a[0] + a[1] * a[1] + a[0] * a[1]);
        double l1 = sqrt(double(sqr(a[0]) + sqr(a[1]) + a[0] * a[1]));
        double l2 = sqrt(double(sqr(a[2]) + sqr(a[3]) + a[2] * a[3]));
        double l3 = sqrt(double(sqr(a[4]) + sqr(a[5]) + a[4] * a[5]));
        //sc(l1);
        double p = 0.5 * (l1 + l2 + l3);
        double s = sqrt(p * (p - l1) * (p - l2) * (p - l3));
        int t0 = floor(s * 4 / sqrt(3.0));
        int t1 = t0 + 1;
        if (s - t0 < t1 - s) ans += t0;
        else ans += t1;
        printf("%d\n", ans);
    }
    return 0;
}















