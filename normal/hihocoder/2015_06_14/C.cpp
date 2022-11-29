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

typedef pair<int, int> pii;
typedef long long LL;

const int N = 205, M = N * N;

int n, m, e;
int head[N], pnt[M], nxt[M], cnt[N];

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
    memset(cnt, 0, sizeof(cnt));
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
    cnt[u]++;
}

int a[N];

int main() {
    int ans, x, y, p;
    scanf("%d %d", &n, &m);
    rep (i, n) scanf("%d", &a[i]);
    init();
    rep (i, m) {
        scanf("%d %d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }
    ans = 0;
    rep (k, 100001) {
        p = -1;
        rep (i, n) {
            if (a[i] >= cnt[i]) {
                p = i;
                break;
            }
        }
       // sc3(p, a[p], cnt[p]);
        if (p == -1) break;
        if (++ans == 100001) break;
        repe (i, p) {
            a[pnt[i]]++;
        }
        a[p] -= cnt[p];
    }
    if (ans == 100001) puts("INF");
    else printf("%d\n", ans);
    return 0;
}























