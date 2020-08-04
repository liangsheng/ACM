
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

const int N = 10005;

int n, m, k;
int a[N], s_min[20][N], s_max[20][N], ln[N];

void RMQInit() {
     int i, j, t, m;
     m = ln[n];
     for(i = 0; i < n; i++) s_min[0][i] = a[i];
     for (j = t = 1; j <= m; j++, t *= 2) {
         for(i = 0; i < n - t; i++) s_min[j][i] = min(s_min[j-1][i], s_min[j-1][i + t]);
         for(i = n - t; i < n; i++) s_min[j][i] = s_min[j-1][i];
     }
     for(i = 0; i < n; i++) s_max[0][i] = a[i];
     for (j = t = 1; j <= m; j++, t *= 2) {
         for(i = 0; i < n - t; i++) s_max[j][i] = max(s_max[j-1][i], s_max[j-1][i + t]);
         for(i = n - t; i < n; i++) s_max[j][i] = s_max[j-1][i];
     }
}

int RMQQuery(int i, int j) {
     if(i == j) return 0;
     if (j < i) j += i, i = j - i, j -= i;
     int m = ln[j - i];
     return max(s_max[m][i], s_max[m][j - (1 << m) + 1]) - min(s_min[m][i], s_min[m][j - (1 << m) + 1]);
}

int b[N];
map<int, int> q;
int head, tail, d[N];

int main() {
    ln[1] = 0, ln[2] = 1, ln[3] = 1, ln[4] = 2;
    int tmp = -1, gg = 1;
    FOR (i, 1, 10000) {
        if (i == gg) tmp++, gg <<= 1;
        ln[i] = tmp;
    }
    //FOR (i, 1, 10) cout << i << ' ' << ln[i] << '\n';
    int cas = 0, ans, l, r, t;
    while (~scanf("%d %d", &n, &m)) {
        q.clear();
        rep (i, n) {
            scanf("%d", &a[i]);
            if (!q.count(a[i])) b[i] = -1, q[a[i]] = i;
            else b[i] = q[a[i]], q[a[i]] = i;
        }
        RMQInit();
        //cout << RMQQuery(3, 5);
        printf("Case #%d:\n", ++cas);
        while (m--) {
            scanf("%d", &k);
            //puts("FFF");
            ans = 0;
            head = tail = 0;
            FOR (i, 0, k - 2) d[tail++] = i;
            for (int i = 0; i + k - 1 < n; i++) {
                //sc(i);
                l = i, r = i + k - 1;
                d[tail++] = r;
                while (head != tail && b[d[head]] < l) head++;
                t = RMQQuery(l, r);
                if (t != k - 1) continue;
                if (head == tail) ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
