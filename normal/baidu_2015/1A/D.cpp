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

const int N = 10005;

int n, e, head, tail;
int x[N], y[N], c[N], h[N];
int a[N * 4];

void init() {
    memset(a, 0, sizeof(a));
}

void add(int k, int s, int t, int x, int y) {
    if (t < x || s > x) return ;
    a[k] += y;
    if (s == t) return ;
    int mid = (s + t) >> 1;
    add(k << 1, s, mid, x, y);
    add(k << 1 | 1, mid + 1, t, x, y);
}

int gao(int k, int s, int t, int id) {
    //printf("s= %d %d %d %d %d", k, s, t, id, a[k]), system("pause");
    if (s == t) return s;
    int mid = (s + t) >> 1;
    if (a[k << 1] >= id) return gao(k << 1, s, mid, id);
    return gao(k << 1 | 1, mid + 1, t, id - a[k << 1]);
}

int main() {
    int cas = 0, m, id, ans;
    char cmd[10];
    while (~scanf("%d", &n)) {
        e = 0;
        rep (i, n) {
            scanf("%s", cmd);
            if (cmd[0] == 'i') {
                x[i] = 0;
                scanf("%d", &y[i]);
                c[e++] = y[i];
            } else if (cmd[0] == 'o') {
                x[i] = 1;
            } else x[i] = 2;
        }
        sort(c, c + e);
        e = unique(c, c + e) - c;
        rep (i, n) {
            if (x[i] != 0) continue;
            y[i] = lower_bound(c, c + e, y[i]) - c;
        }
        printf("Case #%d:\n", ++cas);
        head = tail = 0;
        init();
        rep (i, n) {
//            if (i == 5) {
//                FOR (i, 1, 5) cout << i << ' ' << a[i] << '\n';
//            }
            if (x[i] == 0) {
                h[tail++] = y[i];
                //printf("+ %d", y[i] + 1), system("pause");
                add(1, 1, e, y[i] + 1, 1);
            } else if (x[i] == 1) {
                //printf("- %d", h[head] + 1), system("pause");
                add(1, 1, e, h[head++] + 1, -1);
            } else {
                m = tail - head;
                id = floor(m / 2) + 1;
                //sc(id);
                ans = gao(1, 1, e, id);
                //sc(ans);
                printf("%d\n", c[ans - 1]);
            }
        }
    }
    return 0;
}

















