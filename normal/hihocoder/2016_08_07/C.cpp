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

const int N = 1000000005, LEN = 1005;

LL tim, m, n, e;
string s;
vector<string> a;
vector<LL> ans;
LL X[LEN], Y[LEN], sum[LEN];
bool f[LEN];

void solve() {
    LL tol = (LL) (n + 1) * tim - 1;
    LL u, v, p, L, R, M, ax, ay, D, TD;
    if (tol <= m) {
        cout << "1 " << tol << '\n';
        return ;
    }
    ans.clear();
    memset(f, 0, sizeof(f));
    u = 1, v = 1, p = 0;
    ans.pb(-1);
    FOR (i, 1, LEN - 1) {
        X[i] = 1, Y[i] = 0;
        if (f[p]) break;
        //if (i > 990) sc(i);
        f[p] = 1;
        ans.pb(p);
        FOR (j, p, e - 1) {
            if (v > m) u++, v = 1, X[i]++;
            if (m - v + 1 < SZ(a[j])) {
                u++, v = 1;
                X[i]++;
            }
            v += SZ(a[j]);
            Y[i] = v - 1;
        }
        rep (j, e) {
            if (v > m || m - v + 1 < SZ(a[j])) {
                p = j, v = 1;
                break;
            } else v += SZ(a[j]);
        }
    }
    L = 1, R = SZ(ans) - 1;
    FOR (i, L, R) if (ans[i] == p) {
        M = i;
        break;
    }
    sum[0] = 0;
    FOR (i, L, R) sum[i] = sum[i - 1] + X[i];
    if (tim <= R) {
        ax = sum[tim], ay = Y[tim];
        if (ay == 1) ax--, ay = m;
        else ay--;
        cout << ax << ' ' << ay << '\n';
        return ;
    }
    D = R - M + 1, TD = sum[R] - sum[M - 1];
    u = (tim - R) / D, v = (tim - R) % D;
    ax = sum[R] + u * TD, ay = Y[R];
    if (v == 0) {
        if (ay == 1) ax--, ay = m;
        else ay--;
        cout << ax << ' ' << ay << '\n';
        return ;
    }
    FOR (i, 1, v) {
        rep (j, e) {
            if (m - v < SZ(a[j])) {
                ax++, ay = SZ(a[j]);
            } else ay += SZ(a[j]);
        }
    }
    if (ay == 1) ax--, ay = m;
    else ay--;
    cout << ax << ' ' << ay << '\n';
}

int main() {
    string t;
    while (cin >> tim >> m) {
        getchar();
        getline(cin, s);
        n = SZ(s);
        a.clear();
        rep (i, n) {
            t.clear();
            while (i < n && s[i] != ' ') t.pb(s[i++]);
            a.pb(t);
            a.pb(" ");
        }
        e = SZ(a);
//        rep (i, e) cout << a[i] << "##\n";
        solve();
    }
    return 0;
}










