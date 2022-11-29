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

#define sc(x) cout << #x" = " << x << endl
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, system("pause")
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, system("pause")
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

const LL MOD = 1000000007LL;
const int N = 2;

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

LL extend_gcd(LL a, LL b, LL &x, LL &y) {
    LL t, ret;
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ret = extend_gcd(b,a%b,x,y);
        t = x;
        x = y;
        y = t - a / b * y;
        return ret;
    }
}

LL k1, k2;
LL x, y, ax, ay, z;

int main() {
    LL b1, b2, c1, c2, a1, a2, u, v, p1, p2, d, ans;
    matrix a, t;
//    while (cin >> k1 >> k2) {
//        cin >> x >> y >> ax >> ay;
//        cin >> z;
    srand(1699);
    for (int T = 1; T <= 1000; T++) {
        k1 = rand() % 3 + 1, k2 = rand() % 3 + 1;
        //k1 = 1, k2 = 2;
        LL f[25];
        f[1] = rand() % 3 + 1, f[2] = rand() % 3 + 1;
        //f[1] = 2, f[2] = 3;
        FOR (i, 3, 20) f[i] = (k1 * f[i - 2] + k2 * f[i - 1]) % MOD;
        x = rand() % 10 + 5, y = rand() % 5 + 1 + x;
        //x = 5, y = 7;
        ax = f[x], ay = f[y];
        z = rand() % 10 + 10;
        //z = 14;

        a.x[1][1] = 0, a.x[1][2] = k1;
        a.x[2][1] = 1, a.x[2][2] = k2;

        t = power(a, x - 1);
        b1 = t.x[1][1], b2 = t.x[2][1];
        //sc2(b1, b2);

        t = power(a, y - 1);
        c1 = t.x[1][1], c2 = t.x[2][1];
        //sc2(c1, c2);

        p1 = ay * b2 - ax * c2;
        p2 = ax * c1 - ay * b1;
        d = b2 * c1 - b1 * c2;
        //sc3(p1, p2, d);
        if (d < 0) d = -d, p1 = -p1, p2 = -p2;
        extend_gcd(d, MOD, u, v);
        a1 = p1 * u % MOD;
        a2 = p2 * u % MOD;

        t = power(a, z - 1);
        ans = ((a1 * t.x[1][1] + a2 * t.x[2][1]) % MOD + MOD) % MOD;
        //cout << ans << '\n';
        cout << ans << ' ' << f[z] << '\n';
        if (ans != f[z]) {
            puts("FUCK");
            sc4(k1, k2, f[1], f[2]);
            sc4(a1, a2, x, y);
            sc(z);
            sc4((b1 * a1 + b2 * a2) % MOD, ax, (c1 * a1 + c2 * a2) % MOD, ay);
            FOR (i, 1, 20) cout << "i= " << i << ' ' << f[i] << '\n';
            system("pause");
        }
    }
    return 0;
}













