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

int n, m, k;
int a[1005], b[1005];
vector< pair<int, int> > ans;

void gao(int a[], int n) {
    FOR (i, 2, k) ans.pb(mp(a[1], a[i]));
    FOR (i, 2, k - 1) ans.pb(mp(a[i], a[i + 1]));
    ans.pb(mp(a[k], a[2]));
    for (int i = k + 1; i <= n - 1; i += 2) ans.pb(mp(a[i], a[i + 1]));
    FOR (i, 2, k) FOR (j, k + 1, n) ans.pb(mp(a[i], a[j]));
}

int main() {
    while (~scanf("%d", &k)) {
        if ((k % 2) == 0) {
            puts("NO");
            continue;
        }
        if (k == 1) {
            puts("YES\n2 1\n1 2");
            continue;
        }
        if (k == 3) {
            puts("YES");
            puts("10 15");
            puts("1 2");
            puts("1 3");
            puts("2 4");
            puts("2 5");
            puts("3 4");
            puts("3 5");
            puts("4 5");
            puts("1 6");
            puts("6 7");
            puts("6 8");
            puts("7 9");
            puts("7 10");
            puts("8 9");
            puts("8 10");
            puts("9 10");
            continue;
        }
        n = 2 * k - 3;
        ans.clear();
        FOR (i, 1, n) a[i] = i;
        gao(a, n);
        FOR (i, 1, n) b[i] = i + n;
        gao(b, n);
        puts("YES");
        n = n * 2, m = SZ(ans) + 1;
        printf("%d %d\n", n, m);
        printf("%d %d\n", a[1], b[1]);
        rep (i, m - 1) printf("%d %d\n", ans[i].X, ans[i].Y);
    }
    return 0;
}























