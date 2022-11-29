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

LL w, m;
LL c0, c1, flag;
LL a[25];

void dfs(int p) {
    if (flag) return ;
    if (p == 21) {
        if (c0 + m == c1) flag = 1;
        if (c1 + m == c0) flag = 1;
        return ;
    }
    c0 += a[p];
    dfs(p + 1);
    c0 -= a[p], c1 += a[p];
    dfs(p + 1);
}

int main() {
    LL d = 1;
    FOR (i, 1, 15) d = d * 3;
    cout <<d << '\n' << 100000000;
    while (cin >> w >> m) {
        if (w == 2) {
            puts("YES");
            continue;
        }
        a[0] = 1;
        FOR (i, 1, 20) a[i] = a[i - 1] * w;
        c0 = c1 = 0, flag = 1;
        dfs(0);
    }
    return 0;
}















