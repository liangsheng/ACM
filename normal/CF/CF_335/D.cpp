#include <bits/stdc++.h>

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

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 100005, INF = ~0U >> 2;

struct Node {
    int val, f, id;
    Node() {}
    Node(int A, int B, int C): val(A), f(B), id(C) {}
    bool operator <(const Node& arg) const {
        if (val != arg.val) return val < arg.val;
        return f > arg.f;
    }
} p[N];

int n, m;
pii res[N];

void gao(int &s, int &t) {
    if (s == t - 2) t++, s = 1;
    else s++;
}

int main() {
    int s, t, e, flag;
    while (~scanf("%d %d", &n, &m)) {
        rep (i, m) {
            scanf("%d %d", &p[i].val, &p[i].f);
            p[i].id = i;
        }
        sort(p, p + m);
        if (p[0].f == 0) {
            puts("-1");
            continue;
        }
        e = 1, flag = 1, s = 1, t = 3;
        res[p[0].id] = mp(e, e + 1);
        e++;
        FOR (i, 1, m - 1) {
            if (p[i].f == 0) {
                if (t > e) {
                    flag = 0;
                    break;
                } else {
                    res[p[i].id] = mp(s, t);
                    gao(s, t);
                }
            } else {
                res[p[i].id] = mp(e, e + 1);
                e++;
            }
        }
        if (!flag) puts("-1");
        else {
            rep (i, m) printf("%d %d\n", res[i].X, res[i].Y);
        }
    }
    return 0;
}













