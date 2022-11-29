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

const int N = 100005;

int n;
int a[N];

int main() {
    int n0, p1, p0;
    while (~scanf("%d", &n)) {
        n0 = 0;
        rep (i, n) {
            scanf("%d", &a[i]);
            n0 += (a[i] == 0);
            if (a[i] == 1) p1 = i;
        }
        if (a[n - 1] != 0) {
            puts("NO");
            continue;
        }
        if (n == 1) {
            puts("YES\n0\n");
            continue;
        }
        if (n == 2) {
            if (a[0] == 0) puts("NO");
            else puts("YES\n1->0");
            continue;
        }
        if (n0 == n) {
            puts("YES");
            printf("0->(0");
            FOR (i, 2, n - 2) printf("->0");
            puts(")->0");
            continue;
        }
        if (p1 == n - 2) {
            puts("YES");
            FOR (i, 0, n - 2) printf("%d->", a[i]);
            puts("0\n");
            continue;
        }
        if (p1 < n - 3) {
            puts("YES");
            FOR (i, 0, p1 + 1) printf("%d->", a[i]);
            printf("(0");
            FOR (i, p1 + 3, n - 2) printf("->0");
            puts(")->0");
            continue;
        }
        if (p1 == n - 3) {
            p0 = -1;
            FOR (i, 0, n - 4) if (a[i] == 0) {
                p0 = i;
                break;
            }
            if (p0 == -1) {
                puts("NO");
                continue;
            }
            puts("YES");
            FOR (i, 0, p0) printf("%d->", a[i]);
            printf("(");
            FOR (i, p0 + 1, n - 3) printf("%d->", a[i]);
            printf("%d)->%d\n", a[n - 2], a[n - 1]);
        }
    }
    return 0;
}
