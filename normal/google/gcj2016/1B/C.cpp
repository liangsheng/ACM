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

const int N = 16 + 5;

int T, n, e;
int L[N], R[N];
map<string, int> q;

bool gao(int i) {
    rep (j, n) FOR (k, j + 1, n - 1) {
        if (j == i || k == i) continue;
        if (L[i] == L[j] && R[i] == R[k]) return 1;
        if (L[i] == L[k] && R[i] == R[j]) return 1;
    }
    return 0;
}

int main() {
    //cout << 16LL * 15 * 14 * 13 * 12 *11 * 10 * 9 * 8 * 7 << '\n' << 100000000;
    //file_r("C-small-attempt1.in");
    //file_w("C-small.out");
    cout << (1LL << 16) * 16;
    int cas = 0, x, y, ans;
    string s0, s1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        e = 0, q.clear();
        rep (i, n) {
            cin >> s0 >> s1;
            if (!q.count(s0)) q[s0] = e++;
            if (!q.count(s1)) q[s1] = e++;
            L[i] = q[s0], R[i] = q[s1];
        }
        ans = 0;
        rep (i, n) {
            ans += gao(i);
        }
        if (ans > 14) ans = 14;
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}














