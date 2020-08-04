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

int gao(LL x) {
    int ans = 0;
    LL l, r, mid, sum = 0;
    while (x != 0) {
        l = 1, r = ceil(sqrt(x));
        while (l != r) {
            mid = (l + r) >> 1, mid++;
            if (mid * mid >= x) r = mid - 1;
            else {
                if (mid * mid * mid <= x) l = mid;
                else r = mid - 1;
            }
        }
        //cout << l << ' ';
        sum += l * l * l;
        ans++;
        x -= l * l * l;
    }
    //sc2(ans, sum);
    //cout << 7926744LL * 7926744 * 7926744 << '\n' << 999999993541753LL << '\n';
    //cout << 7926743LL * 7926743 * 7926743 << '\n';
    return ans;
}

LL get(LL x) {
    LL l, r, mid;
    l = 1, r = ceil(x) + 1;
    while (l != r) {
        mid = (l + r) >> 1;
        if (mid * mid >= x) r = mid;
        else {
            if (mid * mid * mid >= x) r = mid;
            else l = mid + 1;
        }
    }
    return l;
}

LL n;

int main() {
    gao(200355);
    //cout << (1000000000000000LL - 99999LL * 99999 * 99999);
    int tim, t;
    LL x, tmp, y, z;
    while (cin >> n) {
//        if (n <= 100000) {
            tim = -1, x = 0;
            for (LL i = n; i >= 1; i--) {
                t = gao(i);
                if (t > tim) tim = t, x = i;
                sc2(i, t);
            }
            cout << tim << ' ' << x << '\n';
//        } else {
//            tim = 9, tmp = 23;
//            while (tmp <= n) {
//                y = get(tmp);
//                z = y * y * y + tmp;
//                if (z > n) break;
//                //sc2(y, z);
//                tim++, tmp = z;
//            }
//            cout << tim << '\n';
//        }
    }
    return 0;
}















