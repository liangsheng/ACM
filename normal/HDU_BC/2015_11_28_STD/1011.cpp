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

int T, n, e;
char s[N];
int a[N];

LL sqr(int x) {
    return (LL) x * x;
}

int main() {
    //srand(100230);
    int cas = 0;
    LL ans, tmp, tol;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        //n = rand() % 10 + 1;
        //rep (i, n) s[i] = rand() % 2 + '0';
        //s[n] = 0;
        n = strlen(s), e = 0, tol = 0;
        rep (i, n) {
            int j = i;
            while (j + 1 < n && s[j + 1] == s[i]) j++;
            tol += sqr(j - i + 1);
            a[e++] = j - i + 1;
            i = j;
        }
        ans = tol;
        //rep (i, e) sc(a[i]);
        rep (i, e - 1) {
            if (a[i] > 1) {
                tmp = tol + 2 + 2LL * (a[i + 1] - a[i]);
                ans = max(tmp, ans);
            } else {
                if (i > 0) tmp = tol - sqr(a[i - 1]) - sqr(a[i]) - sqr(a[i + 1]) + sqr(a[i - 1] + a[i] + a[i + 1]);
                else tmp = tol - sqr(a[i]) - sqr(a[i + 1]) + sqr(a[i] + a[i + 1]);
                ans = max(ans, tmp);
            }
            //sc(ans);
            if (a[i + 1] > 1) {
                tmp = tol + 2 + 2 * (a[i] - a[i + 1]);
                ans = max(tmp, ans);
            } else {
                if (i + 2 < e) tmp = tol - sqr(a[i]) - sqr(a[i + 1]) - sqr(a[i + 2]) + sqr(a[i] + a[i + 1] + a[i + 2]);
                else tmp = tol - sqr(a[i]) - sqr(a[i + 1]) + sqr(a[i] + a[i + 1]);
                ans = max(ans, tmp);
            }
            //sc2(i, ans);
        }
        printf("Case #%d: %I64d\n", ++cas, ans);
  //      tmp = ans;

//        ans = tol;
//        rep (i, n) {
//            if (s[i] == '0') s[i] = '1';
//            else s[i] = '0';
//
//            e = 0, tol = 0;
//            rep (j, n) {
//                int k = j;
//                while (k + 1 < n && s[k + 1] == s[j]) k++;
//                tol += (k - j + 1) * (k - j + 1);
//                j = k;
//            }
//            ans = max(ans, tol);
//
//            if (s[i] == '0') s[i] = '1';
//            else s[i] = '0';
//        }
//        //printf("%I64d\n", ans);
//        if (ans != tmp) sc3(tmp, ans, s), system("pause");
    }
    return 0;
}














