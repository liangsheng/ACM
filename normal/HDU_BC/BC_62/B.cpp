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
#define eps 1e-4
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

const int MOD = 1000000007, N = 70, D = 30;

int T;
int l, r, m;

struct Mat {
    int sz;
    int mat[N][N];

    void e() {
        int i, j;
        memset(mat, 0, sizeof(mat));
        for(i = 0; i < sz; i++) mat[i][i] = 1;
    }

    void clr() {
        memset(mat, 0, sizeof(mat));
    }

    void print() {
        int i, j;
        for (i = 0; i < sz; i++) {
            for (j = 0; j < sz; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
        }
    }

    Mat operator = (Mat b) {
        int i, j;
        sz = b.sz;
        for (i = 0; i < sz; i++)
            for (j = 0; j < sz; j++)
                mat[i][j] = b.mat[i][j];
    }

    Mat operator + (Mat b) {
        int i, j;
        Mat c;
        c.sz = sz;
        c.clr();
        for (i = 0; i < sz; i++)
            for (j = 0; j < sz; j++)
                c.mat[i][j] = ((LL) mat[i][j] + b.mat[i][j]) % MOD;
        return c;
    }

    Mat operator * (Mat b) {
        int i, j, k;
        Mat c;
        c.sz = sz;
        c.clr();
        for (i = 0; i < sz; i++) {
            for (k = 0; k < sz; k++) {
                if (mat[i][k] == 0) continue;
                for (j = 0; j < sz; j++) {
                    if( b.mat[k][j] == 0) continue;
                    c.mat[i][j] = ((LL) mat[i][k] * b.mat[k][j] + c.mat[i][j]) % MOD;
                }
            }
        }
        return c;
    }

    Mat operator ^ (int p) {        //¶þ·ÖÇóÃÝ
        int i, j;
        Mat ret, a;
        ret.sz = sz;
        ret.e();
        a = *this;
        while (p) {
            if (p & 1) ret = ret * a;
            a = a * a;
            p >>= 1;
        }
        return ret;
    }

    Mat operator - (Mat b) {
        int i, j;
        Mat c;
        c.sz = sz;
        c.clr();
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++)
                c.mat[i][j] = mat[i][j] - b.mat[i][j];
        }
        return c;
    }
};

Mat a;
Mat g[D + 5];
int b[N], d[N];

void init() {
    int id, t, x, y;
    a.sz = N;
    a.clr();
    rep (i, 7) rep (j, 10) {
        id = i * 10 + j;
        rep (l, 10) {
            if (j + l == m) continue;
            x = (i * 10 + l) % 7, y = l;
            t = x * 10 + y;
            //sc2(id, t);
            a.mat[id][t]++;
        }
    }
    //g[0].e();
    //FOR (i, 1, D) g[i] = g[i - 1] ^ 2;
}

Mat wo(int x) {
    Mat ans;
    ans.e();
    if (x == 0) return ans;
    if (x % 2) {
        Mat h = wo(x / 2), d = a ^ (x / 2 + 1);
        return h + h * d;
    } else {
        Mat h = wo(x / 2 - 1), d = a ^ (x / 2 + 1);
        return h + h * d + a ^ (x / 2);
    }
}

void gao() {
    int ans = 0;
    init();
    memset(b, 0, sizeof(b));
    FOR (i, 1, 9) b[i % 7 * 10 + i] = 1;
    Mat p = a ^ (l - 1);
    rep (i, N) printf("%d ", b[i]);
    puts("DDDDD");
    Mat q = wo(r - l);
    p = p * q;
    p.print();
    rep (i, N) {
        d[i] = 0;
        rep (j, N) d[i] = (d[i] + (LL) b[j] * p.mat[j][i]) % MOD;
    }
    rep (i, N) cout << d[i] << ' '; cout << '\n';
    rep (i, 10) ans = (ans + d[i]) % MOD;
    printf("%d\n", ans);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &l, &r, &m);
        gao();
    }
    return 0;
}




















