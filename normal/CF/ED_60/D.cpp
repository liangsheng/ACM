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

const int N = 105, MOD = 1000000007;

struct Mat
{
    int size;
    int mat[N][N];

    void e()
    {
        int i, j;
        memset(mat, 0, sizeof(mat));
        for(i = 0; i < size; i++) mat[i][i] = 1;
    }

    void clr()
    {
        int i, j;
        memset(mat, 0, sizeof(mat));
    }

    void print()
    {
        int i, j;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
        }
    }

    Mat operator = (Mat b)
    {
        int i, j;
        size = b.size;
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                mat[i][j] = b.mat[i][j];
    }

    Mat operator + (Mat b)
    {
        int i, j;
        Mat c;
        c.size = size;
        c.clr();
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                c.mat[i][j] = mat[i][j] + b.mat[i][j];
        return c;
    }

    Mat operator * (Mat b)
    {
        int i, j, k;
        Mat c;
        c.size = size;
        c.clr();
        for (i = 0; i < size; i++)
        {
            for (k = 0; k < size; k++)
            {
                if (mat[i][k]==0) continue;
                for (j = 0; j < size; j++)
                {
                    if( b.mat[k][j] == 0) continue;
                    // c.mat[i][j] += mat[i][k] * b.mat[k][j];
                    c.mat[i][j] = ((LL) mat[i][k] * b.mat[k][j] + c.mat[i][j]) % MOD;
                }
            }
        }
        return c;
    }

    Mat operator ^ (LL p)          //二分求幂
    {
        int i, j;
        Mat ret, a;
        ret.size = size;
        ret.e();
        a = *this;
        while (p)
        {
            if (p & 1) ret = ret * a;
            a = a * a;
            p >>= 1;
        }
        return ret;
    }

    Mat operator - (Mat b)
    {
        int i, j;
        Mat c;
        c.size = size;
        c.clr();
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                c.mat[i][j] = mat[i][j] - b.mat[i][j];
        }
        return c;
    }
} a, b;

LL n;
int m;

int main() {
    int ans;
    while (cin >> n >> m) {
        if (n < m) {
            puts("1");
            continue;
        }
        if (n == m) {
            puts("2");
            continue;
        }
        a.size = m;
        a.clr();
        rep (j, m - 1) a.mat[j + 1][j] = 1;
        a.mat[0][m - 1] = 1;
        a.mat[m - 1][m - 1] = 1;
        b = a ^ (n - m);
        ans = 0;
        rep (i, m) ans = ((LL) b.mat[i][m - 1] + ans) % MOD;
        ans = ((LL) ans + b.mat[m - 1][m - 1]) % MOD;
        cout << ans << '\n';
    }
    return 0;
}
