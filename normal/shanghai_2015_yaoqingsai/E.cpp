#include <bits/stdc++.h>

#define file_r(x) freopen(x, stdin, "r")
#define file_w(x) freopen(x, stdout, "w")
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh
#define lowbit(x) ((x) & (-x))

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

struct Node {
    int r, e, l;
    bool operator <(const Node& arg) const {
        return e < arg.e;
    }
} p[N];

int T, n;

int main() {
    int cas = 0, flag, now;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        rep (i, n) scanf("%d %d %d", &p[i].r, &p[i].e, &p[i].l);
        sort(p, p + n);
        flag = 1, now = 0;
        rep (i, n) {
            if (i > 0 && p[i].e < p[i - 1].e + p[i - 1].l) {
                flag = 0;
                break;
            }
            if (p[i].e - now >= p[i].r) {
                now += p[i].l;
                continue;
            } else {
                flag = 0;
                break;
            }
        }
        printf("Case #%d: ", ++cas);
        puts(flag ? "YES" : "NO");
    }
    return 0;
}














