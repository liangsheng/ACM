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

int n, m, T;
string s[25];
map<char, string> q;
set<char> ss;

bool ok(string s) {
    //sc(s);
    int i, j, sz = SZ(s), a = 0, b;
    for (i = 0; i < sz; i++) {
        if (s[i] >= '0' && s[i] <= '9') a = a * 10 + s[i] - '0';
        else break;
    }
    for (; i < sz; ) {
        //sc2(i, s[i]);
        if (s[i + 1] == '=') {
            b = 0;
            for (j = i + 2; ; j++) {
                if (s[j] >= '0' && s[j] <= '9') b = b * 10 + s[j] - '0';
                else break;
            }
            i = j;
            //puts("GG");
            //sc2(a, b);
            if (!(a <= b)) return 0;
            a = b;
        } else {
            b = 0;
            for (j = i + 1; ; j++) {
                if (s[j] >= '0' && s[j] <= '9') b = b * 10 + s[j] - '0';
                else break;
            }
            i = j;
            //puts("HAHA");
            //sc2(a, b);
            if (!(a < b)) return 0;
            a = b;
        }
    }
    return 1;
}

int main() {
    char ch;
    int sz, flag;
    string tmp, num;
    while (~scanf("%d", &n)) {
        m = 0, ss.clear();
        rep (i, n) {
            cin >> s[i];
            sz = SZ(s[i]);
            rep (j, sz) if (s[i][j] >= 'A' && s[i][j] <= 'Z') ss.insert(s[i][j]);
        }
        m = SZ(ss);
        scanf("%d", &T);
        while (T--) {
            q.clear();
            rep (i, m) {
                cin >> ch >> num;
                q[ch] = num;
            }
            flag = 1;
            rep (i, n) {
                tmp.clear();
                sz = SZ(s[i]);
                rep (j, sz) {
                    if (q.count(s[i][j])) tmp += q[s[i][j]];
                    else tmp += s[i][j];
                }
                flag = ok(tmp);
                //sc2(tmp, flag);
                if (!flag) break;
            }
            puts(flag ? "Yes" : "No");
        }
    }
    return 0;
}















