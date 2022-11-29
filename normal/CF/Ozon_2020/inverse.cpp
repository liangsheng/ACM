#include <bits/stdc++.h>
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

const int MOD = 9;

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
T extend_gcd(T a, T b, T &x, T&y) {
    T t, ret;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ret = extend_gcd(b, a % b, x, y);
        t = x;
        x = y;
        y = t - a / b * y;
        return ret;
    }
}

const int MAXN = 105, p = 9;

//1、线性求逆元
int inv[MAXN]; 

//线性求到a的逆元 
void INV(int a, int p) {
    inv[1] = 1;
    for (int i = 2; i <= a; ++i)
        inv[i] = (-(p / i)) * inv[p % i] % p; 
}

//2、单独求某个值的逆元
int INV(int a) {
     if (a == 1) return 1;
     return ((-(p / a) * INV(p % a)) % p);
}

int main() {
    cout << inverse(2, MOD) << '\n';
    
    int x, y;
    extend_gcd(2, MOD, x, y);
    cout << x << '\n';

    cout << INV(2) << '\n';
    return 0;
}
