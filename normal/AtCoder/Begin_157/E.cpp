#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define ins insert
#define rb rbegin
#define be begin
#define er erase
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((LL) (r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)

#define sc(x) cout << #x" = " << x << endl, system("pause")
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, system("pause")
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, system("pause")
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, system("pause")

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 500005, M = 20005, CH = 26;

int n, m;
char s[N];
si q[CH];

void gao() {
    rep (i, CH) q[i].clear();
    rep (i, n) q[s[i] - 'a'].insert(i);

    int cmd, l, r, p, id;
    char ch;
    in(m);
    while (m--) {
        in(cmd);
        if (cmd == 1) {
            scanf("%d %c", &p, &ch), p--;
            if (s[p] == ch) continue;
            q[s[p] - 'a'].erase(p);
            q[ch - 'a'].insert(p);
            s[p] = ch;
        } else {
            in2(l, r), l--, r--;
            int ans = 0, x;
            rep (i, CH) {
                if (q[i].empty()) continue;
                if (*q[i].rbegin() < l) continue;
                p = *q[i].lower_bound(l);
                ans += (p >= l && p <= r);
            }
            printf("%d\n", ans);
        }
    }
}

int main() {
    // si a;
    // a.insert(1), a.insert(3);
    // cout << *a.lower_bound(9) << '\n';
    while (~in(n)) {
        scanf("%s", s);
        gao();
    }
    return 0;
}
