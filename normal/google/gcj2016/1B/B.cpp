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

const int N = 18 + 5;

int T, n;
string C, J;

string AC, AJ;

LL con(string s) {
    LL ans = 0;
    rep (i, n) ans = ans * 10 + s[i] - '0';
    return ans;
}

void gao(string C, string J) {
    //sc2(C, J);
    int f = 0;
    rep (i, n) {
        if (C[i] != '?' && J[i] != '?') {
            if (f != 0) continue;
            if (C[i] < J[i]) f = -1;
            else if (C[i] > J[i]) f = 1;
            continue;
        }
        if (C[i] == '?' && J[i] == '?') {
            if (f == 0) C[i] = J[i] = '0';
            else if (f == -1) C[i] = '9', J[i] = '0';
            else C[i] = '0', J[i] = '9';
            continue;
        }
        if (C[i] == '?') {
            if (f == 0) C[i] = J[i];
            else if (f == -1) C[i] = '9';
            else C[i] = '0';
            continue;
        }
        if (J[i] == '?') {
            if (f == 0) J[i] = C[i];
            else if (f == -1) J[i] = '0';
            else J[i] = '9';
            continue;
        }
    }
    LL x = con(AC), y = con(AJ);
    LL u = con(C), v = con(J);
    if (abs(u - v) <= abs(x - y)) {
        if (abs(u - v) < abs(x - y)) AC = C, AJ = J;
        else if (u < x || (u == x && v < y)) AC = C, AJ = J;
    }
}

int main() {
    file_r("B-large.in");
    file_w("B-large.out");
    int cas = 0;
    cin >> T;
    while (T--) {
        cin >> C >> J;
        string CC = C, JJ = J, cc, jj;
        n = SZ(C);
        AC.clear(), AJ.clear();
        rep (i, n) AC.pb('9'), AJ.pb('0');
        gao(C, J);
        rep (i, n) {
            //sc(i);
            cc = C, jj = J;
            if (cc[i] == '?' && jj[i] == '?') {
                //puts("FGFGFG");
                cc[i] = '0', jj[i] = '1';
                //sc2(cc, jj);
                gao(cc, jj);
                cc[i] = '1', jj[i] = '0';
                gao(cc, jj);
                continue;
            }
            if (cc[i] != '?' && jj[i] != '?') continue;
            if (jj[i] != '?') {
                if (jj[i] != '9') cc[i] = jj[i] + 1, gao(cc, jj);
                if (jj[i] != '0') cc[i] = jj[i] - 1, gao(cc, jj);
                continue;
            }
            if (cc[i] != '?') {
                if (cc[i] != '9') jj[i] = cc[i] + 1, gao(cc, jj);
                if (cc[i] != '0') jj[i] = cc[i] - 1, gao(cc, jj);
            }
        }
        //gao(C, J);
        cout << "Case #" << ++cas << ": " << AC << ' ' << AJ << '\n';

//        C = CC, J = JJ;
//        int a = 99999, b = 0;
//        if (n == 1) FOR (i, 0, 9) FOR (j, 0, 9) {
//            int f = 1, x = i, y = j;
//            FORD (l, n - 1, 0) {
//                if (C[l] != '?') {
//                    if (x % 10 != C[l] - '0') {
//                        f = 0;
//                        break;
//                    }
//                }
//                x /= 10;
//            }
//            if (!f) continue;
//            f = 1;
//            FORD (l, n - 1, 0) {
//                if (J[l] != '?') {
//                    if (y % 10 != J[l] - '0') {
//                        f = 0;
//                        break;
//                    }
//                }
//                y /= 10;
//            }
//            if (!f) continue;
//            if (abs(i - j) <= abs(a - b)) {
//                if (abs(i - j) < abs(a - b)) a = i, b = j;
//                else if (i < a || (i == a && j < b)) a = i, b = j;
//            }
//        } else if (n == 2) FOR (i, 0, 99) FOR (j, 0, 99) {
//            int f = 1, x = i, y = j;
//            FORD (l, n - 1, 0) {
//                if (C[l] != '?') {
//                    if (x % 10 != C[l] - '0') {
//                        f = 0;
//                        break;
//                    }
//                }
//                //sc4(l, C[l], C[l] - '0', x % 10);
//                x /= 10;
//            }
//            if (!f) continue;
//            //sc(i);
//            f = 1;
//            FORD (l, n - 1, 0) {
//                if (J[l] != '?') {
//                    if (y % 10 != J[l] - '0') {
//                        f = 0;
//                        break;
//                    }
//                }
//                y /= 10;
//            }
//            if (!f) continue;
//            //sc2(i, j);
//            if (abs(i - j) <= abs(a - b)) {
//                if (abs(i - j) < abs(a - b)) a = i, b = j;
//                else if (i < a || (i == a && j < b)) a = i, b = j;
//            }
//        } else if (n == 3) FOR (i, 0, 999) FOR (j, 0, 999) {
//            int f = 1, x = i, y = j;
//            FORD (l, n - 1, 0) {
//                if (C[l] != '?') {
//                    if (x % 10 != C[l] - '0') {
//                        f = 0;
//                        break;
//                    }
//                }
//                x /= 10;
//            }
//            if (!f) continue;
//            f = 1;
//            FORD (l, n - 1, 0) {
//                if (J[l] != '?') {
//                    if (y % 10 != J[l] - '0') {
//                        f = 0;
//                        break;
//                    }
//                }
//                y /= 10;
//            }
//            if (!f) continue;
//            if (abs(i - j) <= abs(a - b)) {
//                if (abs(i - j) < abs(a - b)) a = i, b = j;
//                else if (i < a || (i == a && j < b)) a = i, b = j;
//            }
//        }
//        //cout << a << ' ' << b << '\n';
//        if (con(AC) != a || con(AJ) != b) cout << "FUCK " << a << ' ' << b << '\n';
    }
    return 0;
}














