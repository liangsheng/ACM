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
#include <cfloat>
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
#define sqr(r) ((r) * (r))
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

const int N = 300005;

int n, m;
queue<int> q[N];
set<pii> h;
set<pii> :: iterator iter;

int main() {
    int cmd, x, e, ans, t;
    while (~scanf("%d %d", &n, &m)) {
        FOR (i, 1, n) {
            while (!q[i].empty()) q[i].pop();
        }
        h.clear();
        e = 0, ans = 0;
        while (m--) {
            scanf("%d %d", &cmd, &x);
            if (cmd == 1) {
                e++;
                if (q[x].empty()) h.insert(mp(e, x));
                q[x].push(e);
                ans++;
            } else if (cmd == 2) {
                if (!q[x].empty()) {
                    h.erase(mp(q[x].front(), x));
                    while (!q[x].empty()) q[x].pop(), ans--;
                }
            } else if (cmd == 3) {
                while (!h.empty()) {
                    //repit (it, h) cout << it->Y << ' '; system("pause");
                    //sc(x);
                    iter = h.begin();
                    t = iter->Y;
                    if (q[t].front() > x) break;
                    h.erase(iter);
                    q[t].pop();
                    ans--;
                    if (!q[t].empty()) h.insert(mp(q[t].front(), t));
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
