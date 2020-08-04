#include <bits/stdc++.h>

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
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 5, M = 1000000005, TT = 30;

int T, n, m;
int a[N];
vector<pii> ans;
set<pii> s;

int gcd(int x, int y) {
    return x % y ? gcd(y, x % y): y;
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

int main() {
    int cas = 0, tmp, t, l, sz;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        l = 1;
        FOR (i, 1, n) {
            scanf("%d", &a[i]);
            l = lcm(l, a[i]);
        }
        FOR (i, 1, n) {
            for(int j = 0; j < l; j += a[i]) ans.pb(mp(j, i));//, sc2(j, i);
        }
        sort(ans.begin(), ans.end());
        printf("Case #%d: ", ++cas);
        sz = ans.size();
        if (m % sz == 0) printf("%d\n", ans[sz - 1].Y);
        else printf("%d\n", ans[m % sz - 1].Y);
    }
    return 0;
}


















