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

const int N = 200005;

int n;
string s;

LL gao() {
    LL d = 10000000000;
    if (n == 1) return s[0] == '1' ? 2 * d : d;
    if (n == 2) {
        if (s == "11") return d;
        if (s == "00") return 0;
        if (s == "10") return d;
        if (s == "01") return d - 1;
    }
    if (n == 3) {
        if (s == "110") return d;
        if (s == "101" || s == "011") return d - 1;
        return 0;
    }
    if (n == 4) {
        if (s == "1101") return d - 1;
        if (s == "1011") return d - 1;
        if (s == "0110") return d - 1;
        return 0;
    }
    int l = -1;
    rep (i, n - 2) if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0') {
        l = i;
        break;
    }
    if (l == -1 || l > 2) return 0;
    rep (i, n) {
        int d = (i - l + 3) % 3;
        if (d < 2 && s[i] != '1') return 0;
        if (d == 2 && s[i] != '0') return 0;
    }
    if (l == 0) {
        if (n % 3 == 0) return d - n / 3 + 1;
        return d - n / 3;
    }
    if (n % 3 == l) return d - n / 3;
    if (n % 3 > l) return d - n / 3 - 1;
    return d - n / 3;
}

int main() {
    while (cin >> n) {
        cin >> s;
        cout << gao() << '\n';
    }
    return 0;
}