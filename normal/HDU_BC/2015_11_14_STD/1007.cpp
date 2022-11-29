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

const int N = 100005, DEP = 20;

int T, n;
char s[N];

int r[N], rak[N], sa[N], height[N];
int wa[N], wb[N], wc[N], wv[N];

int cmp(int *r ,int a, int b, int j) {
    return r[a] == r[b] && r[a + j] == r[b + j];
}

void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++) wc[i] = 0;
    for (i = 0; i < n; i++) wc[x[i] = r[i]]++;
    for (i = 1; i < m; i++) wc[i] += wc[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--wc[x[i]]] = i;
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
        x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
}

void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    //sa[0] = n, 是人为添加的, 要处理掉
    for (i = 1; i <= n; i++) rak[sa[i]] = i;
    //sa: index range 1~n value range 0~n-1
    //rak: index range 0~n-1 value range 1~n
    //height: index from 1   (height[1] = 0)
    for (i = 0; i < n; height[rak[i++]] = k)
    for (k ? k-- : 0, j = sa[rak[i] - 1]; r[i + k] == r[j + k]; k++);
}

int ln[N], f[DEP][N];

void rmqInit() {
    FOR (i, 1, n) f[0][i] = height[i];
    for (int j = 1, t = 1; j <= ln[n]; j++, t <<= 1) {
        FOR (i, 1, n - t) f[j][i] = min(f[j - 1][i], f[j - 1][i + t]);
        FOR (i, n - t + 1, n) f[j][i] = f[j - 1][i];
    }
}

int rmqFind(int s, int t) {
    if (s == t) return height[s];
    int m = ln[t - s + 1];
    return min(f[m][s], f[m][t - (1 << m) + 1]);
}

const int M = 131072;

int h[M * 2 + 1];

void init() {
    memset(h, 127, sizeof(h));
}

void update(int x, int y) {
    for (h[x += M] = y, x >>= 1; x; x >>= 1) {
        h[x] = min(h[x << 1], h[x << 1 | 1]);
    }
}

int gao(int s, int t) {
    int ans = ~0U >> 1;
    for (s = s + M - 1, t = t + M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
        if (~s & 1) ans = min(ans, h[s ^ 1]);
        if (t & 1) ans = min(ans, h[t ^ 1]);
    }
    return ans;
}

vpii ans;
mii q;
mii :: iterator i0, i1;

int main() {
    int cas = 0, a = 1, b = -1, t, k, tmp;
    FOR (i, 1, 100000) {
        if (i == a) a <<= 1, b++;
        ln[i] = b;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        n = strlen(s);
        rep (i, n) r[i] = s[i] - 'a' + 1;
        r[n] = 0;
        da(r, sa, n + 1, 30);
        calheight(r, sa, n);
        rmqInit();
        //FOR (i, 1, n) cout << i << ' ' << sa[i] << '\n';
        //puts("FFFFF");
        //FOR (i, 1, n) cout << i << ' ' << height[i] << '\n';
        //system("pause");
        //sc(rmqFind(4, 6));
        printf("Case #%d:\n", ++cas);
        ans.clear(), q.clear();
        ans.pb(mp(-1, int(s[0])));
        q[rak[0]] = 0;
        //sc(sa[0]);

        //init();

        FOR (i, 1, n - 1) {
            //sc(i);
            q[rak[i]] = i, a = -1, b = rak[i], k = 0;
            //if (i == 6) {
            //    repit (it, q) cout << it -> X << ' ' << it -> Y << '\n';
            //    system("pause");
            //}
            i0 = q.find(rak[i]);

            //update(rak[i], i);

            //sc(sa[i]);
            if (i0 != q.begin()) {
                --i0;
                a = i0 -> X;
                tmp = rmqFind(a + 1, b);
                //sc3(a, b, tmp);
                if (tmp > k) t = i0 -> Y, k = tmp;
                else if (tmp == k) t = min(t, i0 -> Y);

                //hehe
                while (i0 != q.begin()) {
                    --i0;
                    a = i0 -> X;
                    tmp = rmqFind(a + 1, b);
                    if (tmp < k) break;
                    else t = min(t, i0 -> Y);
                }

            }

            i1 = q.find(rak[i]), i1++;
            if (i1 != q.end()) {
                a = i1 -> X;
                tmp = rmqFind(b + 1, a);
                //sc3(a, b, tmp);
                if (tmp > k) t = i1 -> Y, k = tmp;
                else if (tmp == k) t = min(t, i1 -> Y);

                //hehe
                while (++i1 != q.end()) {
                    a = i1 -> X;
                    tmp = rmqFind(b + 1, a);
                    if (tmp < k) break;
                    else t = min(t, i1 -> Y);
                }


            }
            if (k == 0) ans.pb(mp(-1, int(s[i])));
            else {
                ans.pb(mp(k, t));
                FOR (j, i + 1, i + k - 1) q[rak[j]] = j;
                i += k - 1;
            }

        }
        repit (it, ans) printf("%d %d\n", it -> X, it -> Y);
    }
    return 0;
}
