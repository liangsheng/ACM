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

const int N = 200005;

int r[N], rnk[N], sa[N], height[N];
int wa[N], wb[N], wc[N], wv[N];

int cmp(int *r ,int a, int b, int j) {
    return r[a] == r[b] && r[a + j] == r[b + j];
}

void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x=wa, *y=wb, *t;
    for (i = 0; i < m; i++) wc[i] = 0;
    for (i = 0; i < n; i++) wc[x[i] = r[i]]++;
    for (i = 1; i < m; i++) wc[i] += wc[i-1];
    for (i = n-1; i >= 0; i--) sa[--wc[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; i++) wv[i] = x[y[i]];
        for (i = 0; i < m; i++) wc[i] = 0;
        for (i = 0; i < n; i++) wc[wv[i]]++;
        for (i = 1; i < m; i++) wc[i] += wc[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--wc[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1,x[sa[0]] = 0,i = 1; i < n; i++)
        x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1 : p++;
    }
}

void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    //sa[0] = n, ����Ϊ���ӵ�, Ҫ������
    for (i = 1; i <= n; i++) rnk[sa[i]] = i;
    //sa: index range 1~n value range 0~n-1
    //rnk: index range 0~n-1 value range 1~n
    //height: index from 1   (height[1] = 0)
    for (i = 0; i < n; height[rnk[i++]] = k)
    for (k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
}

int n;
char s[N];

int main() {
    while(~scanf("%s", s)) {
        n = strlen(s);
        rep (i, n) r[i] = s[i] - 'a' + 1, r[i + n] = r[i];
        r[2 * n] = 27;
        r[2 * n + 1] = 0;
        da(r, sa, 2 * n + 2, 30);
        calheight(r, sa, 2 * n + 1);
        // for (int i = 1; i <= n; i++) cout << sa[i] << ' ';
        // puts("");
        for (int i = sa[1], j = 0; j < n; j++) printf("%c", s[(i + j) % n]);
        puts("");
    }
    return 0;
}
