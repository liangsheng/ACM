#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const int N1 = 300005, N2 = N1 * 2, DEP = 20, INF = ~0U >> 2;

int ln[N2];

int n, e, m, q;
int head[N1], R[N1], D[N2], E[N2], deepth[N1];
int s[DEP][N2];

struct NODE {
    int u, v;
    int next;
} edge[N1 * 2];

void init() {
    e = m = 0;
    memset(head, -1, sizeof(head));
    ln[1] = 0, ln[2] = 1, ln[3] = 1, ln[4] = 2;
    int tmp = -1, gg = 1;
    FOR (i, 1, 300000) {
        if (i == gg) tmp++, gg <<= 1;
        ln[i] = tmp;
    }
}

void add_edge(int u, int v) {
    edge[e].u = u;
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}

void DFS(int u, int deep, int fa) {
    int i;
    R[u] = m;
    E[m++] = u;
    deepth[u] = deep;
    for (i = head[u]; i != -1; i = edge[i].next) {
        if (edge[i].v == fa) continue;
        DFS(edge[i].v, deep + 1, u);
        E[m++] = u;
    }
}


//!!!!!m  not n
int RMQ_Init() {
    int i, j, t, m1;
    m1 = ln[m];               //!!!
    for(i = 0; i < m; i++) s[0][i] = i;
    for (j = t = 1; j <= m1; j++, t *= 2) {
        for(i = 0; i < m - t; i++) s[j][i] = D[s[j-1][i]] < D[s[j-1][i + t]] ? s[j - 1][i] : s[j - 1][i + t];
        for(i = m - t; i < m; i++) s[j][i] = s[j-1][i];
    }
    return 1;
}

int RMQ_Query(int i, int j) {
    if(i == j) return i;
    if (j < i) j += i, i = j - i, j -= i;
    int m1 = ln[j - i];
    return D[s[m1][i]] < D[s[m1][j - (1 << m1) + 1]] ? s[m1][i] : s[m1][j - (1 << m1) + 1];
}

int a[N1 * 4], b[N1 * 4];

void build(int k, int s, int t) {
    int mid = (s + t) >> 1;
    if (s == t) a[k] = b[k] = R[s];
    else {
        build(k << 1, s, mid);
        build(k << 1 | 1, mid + 1, t);
        a[k] = min(a[k << 1], a[k << 1 | 1]);
        b[k] = max(b[k << 1], b[k << 1 | 1]);
    }
}

int gaoMin(int k, int s, int t, int l, int r) {
    int mid = (s + t) >> 1;
    if (t < l || s > r) return INF;
    if (s >= l && t <= r) return a[k];
    return min(gaoMin(k << 1, s, mid, l, r), gaoMin(k << 1 | 1, mid + 1, t, l, r));
}

int gaoMax(int k, int s, int t, int l, int r) {
    int mid = (s + t) >> 1;
    if (t < l || s > r) return -1;
    if (s >= l && t <= r) return b[k];
    return max(gaoMax(k << 1, s, mid, l, r), gaoMax(k << 1 | 1, mid + 1, t, l, r));
}

int main() {
    int x, y, l, r;
    while (~scanf("%d", &n)) {
        init();
        rep (i, n - 1) {
            scanf("%d %d", &x, &y);
            add_edge(x, y);
            add_edge(y, x);
        }
        DFS(1, 0, -1);
        rep (i, m) D[i] = deepth[E[i]];
        //rep (i, m) cout << D[i] << ' ';
       // puts("");
//
       // FOR (i, 1, n) cout << R[i] << ' ';
        //puts("");
        RMQ_Init();
        //cout << R[2] << ' ' << R[5] << '\n';
        //cout << E[RMQ_Query(R[2], R[3])];
        scanf("%d", &q);
        build(1, 1, n);
        //FOR (i, 1, 9) cout << i << ' ' << b[i] << '\n';
        while (q--) {
            scanf("%d %d", &x, &y);
            l = gaoMin(1, 1, n, x, y);
            r = gaoMax(1, 1, n, x, y);
            //sc2(l, r);
            printf("%d\n", E[RMQ_Query(l, r)]);
        }
    }
    return 0;
}



























