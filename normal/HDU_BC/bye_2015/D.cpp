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

const int N = 5005, MOD = 1000000007;

char str[N];
int sa[N]; //index range 1~n value range 0~n-1
int rnk[N]; //index range 0~n-1 value range 1~n
int height[N]; //index from 1   (height[1] = 0)
int r[N], wa[N], wb[N], wc[N], wv[N];

int cmp(int *r, int a, int b, int j) {
	return r[a] == r[b] && r[a + j] == r[b + j];
}

void da(int *r, int *sa, int n, int m) {
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i < m; i++) wc[i] = 0;
	for (i = 0; i < n; i++) wc[x[i] = r[i]]++;
	for (i = 1; i < m; i++) wc[i] += wc[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--wc[x[i]]] = i;
	for (j = 1, p = 1; p < n; j *= 2, m = p) {
		for (p = 0, i = n - j; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0; i < n; i++) wv[i] = x[y[i]];
		for (i = 0; i < m; i++) wc[i] = 0;
		for (i = 0; i < n; i++) wc[wv[i]]++;
		for (i = 1; i < m; i++) wc[i] += wc[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--wc[wv[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		}
	}
}

void calheight(int *r, int *sa, int n) {
	int i, j, k = 0;
    //sa[0] = n, 是人为添加的, 要处理掉
    for (i = 1; i <= n; i++) rnk[sa[i]] = i;
    //sa: index range 1~n value range 0~n-1
    //rnk: index range 0~n-1 value range 1~n
    //height: index from 1   (height[1] = 0)
	for (i = 0; i < n; height[rnk[i++]] = k) {
		for (k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
	}
}

int n;
int ln[N];
int s[N][20];

void init() {
    int i, j, t, m = ln[n];
    for (i = 1; i <= n; i++) s[i][0] = height[i];
    for (j = t = 1; j <= m; j++, t *= 2) {
        for (i = 1; i <= n - t; i++) s[i][j] = min(s[i][j - 1], s[i + t][j - 1]);
        for (i = n - t + 1; i <= n; i++) s[i][j] = s[i][j - 1];
    }
}

int find(int i, int j) {
    if (i == j) return height[i];
    if (i > j) swap(i, j);
    int m = ln[j - i];
    return min(s[i][m], s[j - (1 << m) + 1][m]);
}

int dp[N][N];

int main() {
    int t, p, a, b;
    ln[1] = 0, t = 0, p = 2;
    FOR (i, 2, N - 1) {
        if (i == p) t++, p <<= 1;
        ln[i] = t;
    }
    while (~scanf("%d", &n)) {
        scanf("%s", str);
        rep (i, n) r[i] = str[i] - '0' + 1;
        r[n] = 0;
        da(r, sa, n + 1, 28);
        calheight(r, sa, n);
        init();
//        FOR (i, 1, 6) cout << sa[i] << '\n';
//        sc2(rnk[2], rnk[4]);
//        cout << find(rnk[4] + 1, rnk[2]) << '\n';
        FOR (i, 1, n) {
            dp[i][i] = 1;
            FOR (j, 1, i - 1) {
                //sc2(i, j);
                if (str[i - j] == '0') dp[i][j] = 0;
                else {
                    if (i - j < j) dp[i][j] = dp[i - j][i - j];
                    else {
                        a = rnk[i - j], b = rnk[i - j - j];
                        if (a > b) swap(a, b);
                        t = find(a + 1, b);
                        //sc(t);
                        if (t >= j || str[i - j - j + t] > str[i - j + t]) dp[i][j] = dp[i - j][j - 1];
                        else dp[i][j] = dp[i - j][j];
                    }
                    //sc3(i, j, dp[i][j]);
                }
            }
            //FOR (j, 1, i) cout << "j= " << j << " " << dp[i][j] << '\n'; system("pause");
            FOR (j, 2, i) dp[i][j] = ((LL) dp[i][j - 1] + dp[i][j]) % MOD;
        }
        printf("%d\n", dp[n][n]);
    }
    return 0;
}















