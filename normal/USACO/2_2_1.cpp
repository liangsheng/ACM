/*
ID: ls_02221
PROG: preface
LANG: C++
*/
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

const int N = 3505;

string s[N];

void gao(int y) {
    int x = y;
    s[y].clear();
    if (x >= 3000) s[y] += "MMM";
    else if (x >= 2000) s[y] += "MM";
    else if (x >= 1000) s[y] += "M";

    x = x % 1000;
    if (x >= 900) s[y] += "CM";
    else if (x >= 800) s[y] += "DCCC";
    else if (x >= 700) s[y] += "DCC";
    else if (x >= 600) s[y] += "DC";
    else if (x >= 500) s[y] += "D";
    else if (x >= 400) s[y] += "CD";
    else if (x >= 300) s[y] += "CCC";
    else if (x >= 200) s[y] += "CC";
    else if (x >= 100) s[y] += "C";

    x = x % 100;
    if (x >= 90) s[y] += "XC";
    else if (x >= 80) s[y] += "LXXX";
    else if (x >= 70) s[y] += "LXX";
    else if (x >= 60) s[y] += "LX";
    else if (x >= 50) s[y] += "L";
    else if (x >= 40) s[y] += "XL";
    else if (x >= 30) s[y] += "XXX";
    else if (x >= 20) s[y] += "XX";
    else if (x >= 10) s[y] += "X";

    x = x % 10;
    if (x >= 9) s[y] += "IX";
    else if (x >= 8) s[y] += "VIII";
    else if (x >= 7) s[y] += "VII";
    else if (x >= 6) s[y] += "VI";
    else if (x >= 5) s[y] += "V";
    else if (x >= 4) s[y] += "IV";
    else if (x >= 3) s[y] += "III";
    else if (x >= 2) s[y] += "II";
    else if (x >= 1) s[y] += "I";
}

int main() {
    file_r("preface.in");
    file_w("preface.out");
    int ci, cv, cx, cl, cc, cd, cm, n;
    FOR (i, 1, 3500) gao(i);
    while (~scanf("%d", &n)) {
        ci = cv = cx = cl = cc = cd = cm = 0;
        FOR (i, 1, n) repit (it, s[i]) {
            if (*it == 'I') ci++;
            else if (*it == 'V') cv++;
            else if (*it == 'X') cx++;
            else if (*it == 'L') cl++;
            else if (*it == 'C') cc++;
            else if (*it == 'D') cd++;
            else if (*it == 'M') cm++;
        }
        if (ci != 0) printf("I %d\n", ci);
        if (cv != 0) printf("V %d\n", cv);
        if (cx != 0) printf("X %d\n", cx);
        if (cl != 0) printf("L %d\n", cl);
        if (cc != 0) printf("C %d\n", cc);
        if (cd != 0) printf("D %d\n", cd);
        if (cm != 0) printf("M %d\n", cm);
    }
    return 0;
}
