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

const int N = 2000000;

int n;
vi a[2];
bool f[N + 5];

int main() {
    FOR (i, 2, N) {
        if (f[i]) continue;
        for (LL j = (LL) i * i; j <= N; j += i) f[j] = 1;
    }
    int x;
    scanf("%d", &n);
    rep (i, n) {
        scanf("%d", &x);
        a[x % 2].pb(x);
    }
    int cnt = 0;
    repit (it, a[1]) cnt += (*it == 1);
    if (cnt >= 2) {
        int flag = 0;
        repit (it, a[0]) if (!f[*it + 1]) {
            flag = *it;
            break;
        }
        repit (it, a[1]) if (*it != 1 && !f[*it + 1]) {
            flag = *it;
            break;
        }
        if (flag) {
            printf("%d\n", cnt + 1);
            rep (i, cnt) printf("1 ");
            printf("%d\n", flag);
        } else {
            printf("%d\n", cnt);
            rep (i, cnt - 1) printf("1 ");
            puts("1");
        }
        return 0;
    }
    repit (i, a[0]) repit (j, a[1]) {
        if (!f[*i + *j]) {
            printf("%d\n%d %d\n", 2, *i, *j);
            return 0;
        }
    }
    printf("1\n%d\n", x);
    return 0;
}
