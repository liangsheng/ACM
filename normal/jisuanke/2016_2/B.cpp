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

const int N = 100005;

int T, res;
int a, b, c;
int d[3][3] = {1, 1, 1, 2, 1, 0, 1, 2, 0};

int gao(int a, int b) {
    int x, y, ans;
    if (b > a) swap(a, b);
    x = y = b / 3;
    ans = 2 * x;
    a -= x * 3, b -= x * 3;
    if (a >= 2 && b >= 1) ans++;
    return ans;
}

int solve(int a, int b, int c) {
    if (b > a) swap(a, b);
    if (c == 0) return gao(a, b);
    int ans = 0, t;
    int d = a - b;
    //sc(d);
    if (a < d * 3 || b < d * 2 || c < d) {
        t = min(a / 3, b / 2);
        t = min(t, c);
        ans = t * 2;
        a -= t * 3, b -= t * 2, c -= t;
        if (c == 0) {
            ans--;
            a += 2, b += 1;
            ans += gao(a, b);
            //sc(ans);
            return ans;
        }
        //sc4(a, b, c, ans);
        if (a > 0 && b > 0 && c > 0) {
                ans++, a--, b--, c--;
            if (a > 0 && b > 0) ans += gao(a, b);
        }
        //sc(ans);
        return ans;
    }
    //sc4(a, b, c, ans);
    ans = d * 2;
    a -= d * 3, b -= d * 2, c -= d;
    if (c == 0) {
        ans--;
        a += 2, b += 1;
        ans += gao(a, b);
        return ans;
    }
    t = min(a / 5, c / 2);
    ans += t * 4;
    a -= 5 * t, b -= 5 * t, c -= t * 2;
    if (a > 0 && b > 0 && c > 0) {
        ans++, a--, b--, c--;
        if (a >= 2 && b >= 1) {
            ans++, a -= 2, b -= 1;
            if (a > 0 && b > 0 && c > 0) ans++, a--, b--, c--;
            if (a > 0 && b > 0) ans += gao(a, b);
        }
    }
    //sc(ans);
    return ans;
}

void dfs(int a, int b, int c, int st, int id) {
    res = max(res, st);
    int x = a - d[id][0];
    int y = b - d[id][1];
    int z = c - d[id][2];
    if (x < 0 || y < 0 || z < 0) return ;
    rep (i, 3) {
        if (i == id) continue;
        dfs(x, y, z, st + 1, i);
    }
}

int main() {
    int x, y, z, t, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        //res = 0;
        //rep (i, 3) dfs(a, b, c, 0, i);
        ans = solve(a, b, c);
        if (a >= 2 && b >= 1 && c >= 1) ans = max(ans, 1 + solve(a - 2, b - 1, c));
        printf("%d\n", ans);
    }
//    FOR (i, 0, 25) FOR (j, 0, i) FOR (k, 0, j) {
//        int ans = solve(i, j, k);
//        if (i >= 2 && j >= 1 && k >= 1) ans = max(ans, 1 + solve(i - 2, j - 1, k));
//        res = 0;
//        rep (ii, 3) dfs(i, j, k, 0, ii);
//        if (ans != res) sc3(i, j, k), sc2(ans, res);
//    }
//    puts("GOOD");
    return 0;
}
















