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

const int N = 100005;

int T, n, a, b;
string s;
int g[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int ch(string s) {
    int ans = 0, i;
    for (i = 0; s[i]; i++) ans = ans * 10 + s[i] - '0';
    return ans;
}

bool judge(int year, int mon, int day) {
    if (year < 1980 || year > 2016) return 0;
    if (mon < 1 || mon > 12) return 0;
    if (mon != 2) {
        if (day >= 1 && day <= g[mon]) return 1;
        return 0;
    }
    if (day >= 1 && day <= g[2]) return 1;
    int flag;
    flag = (year % 4 == 0);
    if (flag && day == 29) return 1;
    return 0;
}

int main() {
    LL ans;
    int year, mon, day, flag;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        ans = 0;
        rep (k, n) {
            cin >> s;
            if (s[6] == s[7] && s[7] == s[8] && s[8] == s[9] && s[9] == s[10]) ans += a;
            else if (s[6] + 1 == s[7] && s[7] + 1 == s[8] && s[8] + 1 == s[9] && s[9] + 1 == s[10]) ans += a;
            else if (s[6] - 1 == s[7] && s[7] - 1 == s[8] && s[8] - 1 == s[9] && s[9] - 1 == s[10]) ans += a;
            else {
                year = ch(s.substr(3, 4));
                mon = ch(s.substr(7, 2));
                day = ch(s.substr(9, 2));
                flag = judge(year, mon, day);
                if (flag) ans += a;
                else ans += b;
            }
            //sc(ans);
        }
        cout << ans << '\n';
    }
    return 0;
}














