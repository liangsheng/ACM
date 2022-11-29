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

const int N = 200005;

int n, m;
LL L[N], R[N], a[N];
int c[N];
pair<LL, int> b[N];
int ans[N];
set< pair<int, int> > s;
pair<pair<int, int>, int> p[N];

int main() {
    int i1, i2, flag, id, now;
    LL l, r;
    while (~scanf("%d %d", &n, &m)) {
        rep (i, n) scanf("%I64d %I64d", &L[i], &R[i]);
        rep (i, m) {
            scanf("%I64d", &b[i].X);
            b[i].Y = i + 1;
        }
        sort(b, b + m);
        rep (i, m) {
            c[i] = b[i].Y;
            a[i] = b[i].X;
        }
        flag = 1;
        rep (i, n - 1) {
            l = L[i + 1] - R[i];
            r = R[i + 1] - L[i];
            if (a[m - 1] < l || a[0] > r) {
                flag = 0;
                break;
            }
            i1 = lower_bound(a, a + m, l) - a;
            i2 = upper_bound(a, a + m, r) - a - 1;
            p[i] = mp(mp(i1, i2), i);
        }
        if (!flag) {
            puts("No");
            continue;
        }
        sort(p, p + n - 1);
        now = 0, s.clear();
        rep (i, m) {
            while (now < n - 1 && p[now].X.X == i) s.insert(mp(p[now].X.Y, p[now].Y)), now++;
            if (!s.empty()) {
                set< pair<int, int> > :: iterator it = s.begin();
                i2 = it->X, id = it->Y;
                if (i > i2) {
                    flag = 0;
                    break;
                }
                ans[id] = c[i];
                s.erase(it);
            }
        }
        if (!flag) puts("No");
        else {
            puts("Yes");
            rep (i, n - 1) printf("%d ", ans[i]);
            puts("");
        }
    }
    return 0;
}



















