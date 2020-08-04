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
#include <bitset>
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

const int N = 70;

LL u, v;

void gao() {
    if (u > v) {
        puts("-1");
        return ;
    }
    if (u == 0) {
        if (v == 0) {
            puts("0");
            return ;
        }
        if (v % 2) {
            puts("-1");
            return ;
        }
        cout << 2 << '\n' << v / 2 << ' ' << v / 2 << '\n';
        return ;
    }
    if (u == v) {
        cout << 1 << '\n' << u << '\n';
        return ;
    }
    if ((u + v) % 2) {
        puts("-1");
        return ;
    }
    bitset<N> x(u), y(v);

    int l = -1, r = -1;
    rep (i, N) if (x[i] == 0 && y[i] == 0) {
        r = i;
        break;
    }
    FORD (i, N, 0) if (x[i] ^ y[i]) {
        l = i;
        break;
    }
    if (r == -1 || r > l) {
        puts("3");
        bitset<N> a, b, c;
        rep (i, N) {
            if (x[i] == y[i]) {
                if (x[i] == 0) a[i] = 0, b[i] = 0, c[i] = 0;
                else a[i] = 1, b[i] = 0, c[i] = 0;
            } else {
                b[i - 1] = 1, c[i - 1] = 1;
                if (x[i] == 1) {
                    a[i] = 0, b[i] = 0, c[i] = 1;
                } else {
                    a[i] = 0, b[i] = 0, c[i] = 0;
                }
            }
        }
        cout << a.to_ullong() << ' ' << b.to_ullong() << ' ' << c.to_ullong() << '\n';
        return ;
    }
    
    // 1 0 1 0
    // 1 1 0 0
    puts("2");
    rep (i, N) {
        bitset<N> a, b;
        if (x[i] == y[i]) {
            if (x[i] == 0) a[i] = 0, b[i] = 0;
            else a[i] = 1, b[i] = 0;
        } else {
            x[r] = 1, y[r] = 1;
            if ()
        }
    }
}

int main() {
    while (cin >> u >> v) gao();
    return 0;
}
