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

int n, m, e;
int b[N], c[N];
vector<int> a[N];

int main() {
    int sz, x, p, ans, id;
    while (~scanf("%d %d", &n, &m)) {
        e = 0;
        rep (i, m) a[i].clear();
        rep (k, m) {
            scanf("%d", &c[k]);
            rep (i, c[k]) {
                scanf("%d", &x);
                a[k].pb(x);
                if (x == 1) p = k;
            }
        }
        id = c[p];
        rep (i, c[p]) {
            if (a[p][i] != i + 1) {
                id = i;
                break;
            }
        }
        ans = 0;
        rep (i, m) {
            if (i != p) ans += c[i] - 1;
            else ans += c[i] - id;
            //sc2(i, ans);
        }
        ans += n - id;
        printf("%d\n", ans);
    }
    return 0;
}




















