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
#include <stack>
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

const int N = 15, M = 105;

int f[N];
stack<int> q;

void gao(string s) {
    rep (i, s.size()) {
        if (s[i] == '[' || s[i] == '{') q.push(i);
        else f[q.top()] = i, q.pop();
    }
}

string change(string s, int l, int r) {
    int id = 0, n = r - l + 1, k;
    if (n == 2) return s.substr(l, r - l + 1);
    vector<string> a;
    k = l + 1;
    while (k != r) {
        // printf("k= %d %d", k, f[k]);
        a.pb(change(s, k, f[k]));
        k = f[k] + 1;
    }
    // repit (it, a) cout << *it << ' ';
    // puts("");
    if (s[l] == '[') {
        string ans = "[";
        repit (it, a) ans += *it;
        ans += "]";
        return ans;
    }
    sort(a.begin(), a.end());
    string ans = "{" + a[0];
    FOR (i, 1, a.size() - 1) if (a[i] != a[i - 1]) ans += a[i];
    ans += "}";
    return ans;
}

int n;
string a, b, x, y;

int main() {
    while (~in(n)) {
        rep (i, n) {
            cin >> a >> b;
            gao(a);
            x = change(a, 0, a.size() - 1);
            gao(b);
            y = change(b, 0, b.size() - 1);
            // cout << "x= " << x << '\n';
            // cout << "y= " << y << '\n'; 
            puts(x == y ? "YES" : "NO");
        }
    }
    return 0;
}
