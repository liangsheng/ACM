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

int n, l, r, x, ans, e;
int a[N], b[N];

void dfs(int p, int tol) {
    if (p == n) {
        if (e < 2) return ;
        if (tol < l || tol > r) return ;
        if (b[e - 1] - b[0] < x) return ;
        ans++;
        //rep (i, e) cout << b[i] << ' ';
        //system("pause");
        return ;
    }
    dfs(p + 1, tol);
    b[e++] = a[p];
    dfs(p + 1, tol + a[p]);
    e--;
}

int main() {
    while (~scanf("%d %d %d %d", &n, &l, &r, &x)) {
        rep (i, n) scanf("%d", &a[i]);
        sort(a, a + n);
        ans = 0, e = 0;
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}













