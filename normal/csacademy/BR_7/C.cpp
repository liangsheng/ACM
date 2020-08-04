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

const LL MOD = 1000000007LL;
const int N = 3;

struct matrix {
    LL x[N + 1][N + 1];

    matrix() {
        memset(x, 0, sizeof(x));
    }

    matrix(LL init) {
        memset(x, 0, sizeof(x));
        for(int i = 1; i <= N; i++)
            x[i][i] = init;
    }

    matrix operator +(matrix that) {
        matrix ret;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                ret.x[i][j] = (x[i][j] + that.x[i][j]) % MOD;
        return ret;
    }

    matrix operator -(matrix that) {
        matrix ret;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                ret.x[i][j] = (x[i][j] - that.x[i][j] + MOD) % MOD;
        return ret;
    }

    matrix operator *(matrix that) {
        matrix ret;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                for(int k = 1; k <= N; k++)
                    ret.x[i][j] = (ret.x[i][j] + x[i][k] * that.x[k][j]) % MOD;
        return ret;
    }
} I(1);

matrix power(matrix b, LL e) {
    matrix ret = I;
    while (e) {
        if (e & 1) ret = ret * b;
        b = b * b;
        e /= 2;
    }
    return ret;
}

/*  Note
    1. Set N: matrix size
    2. Set MOD
*/

/*  Eaxmple
    matrix init, trans;
    init.x[1][1] = 2, init.x[2][1] = 1;
    trans.x[1][1] = 2, trans.x[1][2] = 1, trans.x[2][2] = 2;
    cout << (power(trans, 5) * init).x[1][1] << endl;
*/

int main() {
    LL n;
    matrix a;
    a.x[1][1] = 0, a.x[1][2] = MOD - 2, a.x[1][3] = 0;
    a.x[2][1] = 1, a.x[2][2] = 5, a.x[2][3] = 0;
    a.x[3][1] = 0, a.x[3][2] = 1, a.x[3][3] = 1;
    while (cin >> n) {
        if (n == 1) puts("1");
        else if (n == 2) puts("5");
        else {
            matrix t = power(a, n - 2);
            LL L = (1 * t.x[1][1] + 6 * t.x[2][1] + 1 * t.x[3][1]) % MOD;
            LL R = (1 * t.x[1][2] + 6 * t.x[2][2] + 1 * t.x[3][2]) % MOD;
            cout << (R - L + MOD) % MOD << '\n';
        }
    }
    return 0;
}
