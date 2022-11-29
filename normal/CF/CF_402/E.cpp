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

#define sc(x) cout << #x" = " << x << endl
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl

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

const int N = 5005;

struct Node {
    bool flag;    //0: 2, 1: 4
    int idx, idy, idz;
    string x, y, z, op;
} p[N];

int n, m, e;
int h[N];
map<string, int> q;

int gao(int pos, int val) {
    int ans = 0, p0, p1;
    rep (i, n) {
        if (p[i].flag == 0) {
            if (p[i].idy == -1) h[i] = val;
            else if (p[i].idy >= 0) h[i] = h[p[i].idy];
            else h[i] = p[i].y[pos] - '0';
        } else {
            if (p[i].idy == -1) p0 = val;
            else if (p[i].idy >= 0) p0 = h[p[i].idy];
            else p0 = p[i].y[pos] - '0';
            
            if (p[i].idz == -1) p1 = val;
            else if (p[i].idz >= 0) p1 = h[p[i].idz];
            else p1 = p[i].z[pos] - '0';
            
            if (p[i].op[0] == 'A') h[i] = p0 & p1;
            else if (p[i].op[0] == 'O') h[i] = p0 | p1;
            else h[i] = p0 ^ p1;
                     
        }
        ans += h[i];
    }
    return ans;
}

string findMin() {
    int x, y;
    string ans;
    rep (i, m) {
        x = gao(i, 0);
        y = gao(i, 1);
        if (x <= y) ans.pb('0');
        else ans.pb('1');
    }
    return ans;
}

string findMax() {
    int x, y;
    string ans;
    rep (i, m) {
        x = gao(i, 0);
        y = gao(i, 1);
        if (x >= y) ans.pb('0');
        else ans.pb('1');
    }
    return ans;
}

int main() {
    int sz;
    vi a;
    string ans0, ans1;
    string s, x, y, z, op;
    while (~in2(n, m)) {
        e = 0;
        q.clear();
        q["?"] = -1;
        getchar();
        rep (i, n) {
            getline(cin, s);
            sz = int(SZ(s));
            a.clear();
            rep (j, sz) if (s[j] == ' ') a.pb(j);
            q[s.substr(0, a[0])] = e++;
            if (SZ(a) == 2) {
                p[i].flag = 0;
                y = s.substr(a[1] + 1, SZ(s) - a[1] - 1);
                p[i].idx = i;
                if (y[0] == '0' || y[0] == '1') p[i].y = y, p[i].idy = -2;
                else p[i].idy = q[y];
//                sc3(i, p[i].idy, p[i].y);
            } else {
                p[i].flag = 1;
                y = s.substr(a[1] + 1, a[2] - a[1] - 1);
                op = s.substr(a[2] + 1, a[3] - a[2] - 1);
                z = s.substr(a[3] + 1, SZ(s) - a[3] - 1);
                p[i].idx = i;
                if (y[0] == '0' || y[0] == '1') p[i].y = y, p[i].idy = -2;
                else p[i].idy = q[y];
                if (z[0] == '0' || z[0] == '1') p[i].z = z, p[i].idz = -2;
                else p[i].idz = q[z];
                p[i].op = op;
//                sc4(i, p[i].idy, p[i].idz, z);
            }
        }
        ans0 = findMin();
        ans1 = findMax();
        cout << ans0 << '\n' << ans1 << '\n';
    }
    return 0;
}
