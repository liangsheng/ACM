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
int a[N * 2], b[N * 2];
int l[N], r[N];

void gao(int he, int ta, int p) {
    //sc3(he, ta, p);
    if (he + 1 == ta) return ;
    for (int i = he + 1; i < ta; ) {
        int u = b[i];
        int x = l[b[i]], y = r[b[i]];
        printf("%d %d\n", p, u);
        gao(x, y, u);
        i = y + 1;
    }
}

int main() {
    char cmd[10];
    while (~scanf("%d", &n)) {
        rep (i, 2 * n) {
            scanf("%s %d", cmd, &b[i]);
            if (cmd[0] == 'i') a[i] = 0;
            else a[i] = 1;
            if (a[i] == 0) l[b[i]] = i;
            else r[b[i]] = i;
        }
        gao(0, 2 * n - 1, b[0]);
    }
    return 0;
}


















