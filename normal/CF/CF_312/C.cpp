#include <bits/stdc++.h>

#define file_r(x) freopen(x, stdin, "r")
#define file_w(x) freopen(x, stdout, "w")
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh

#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define be begin
#define nb rbegin
#define er erase
#define SZ(c) c.size()

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 100005, INF = ~0U >> 1;

int n, maxi;
int a[N], f[N];
int b[N][20];
int e[N];

void gao(int id)  {
    int x = a[id];
    e[id] = 0;
    while (x != 0) {
        b[id][e[id]++] = x & 1;
        x >>= 1;
    }
    maxi = max(maxi, e[id]);
    rep (i, e[id] / 2) swap(b[id][i], b[id][e[id] - 1 - i]);
}

int main() {
    int ans, ck, c0, c1, tmp, p;
    while (~scanf("%d", &n)) {
        rep (i, n) scanf("%d", &a[i]);
        maxi = 0;
        rep (i, n) gao(i);
        ans = INF;
        //sc(maxi);
        rep (k, maxi) {
            ck = c0 = c1 = 0, tmp = 0;
            rep (i, n) {
                if (k >= e[i]) ck++;
                else if (b[i][k] == 0) c0++;
                else c1++;
                tmp += e[i] - 1 - k;
            }
          //  sc4(k, ck, c0, c1);
            if ((c0 != n) && (c1 != n)) {
                p = k;
                break;
            } else ans = tmp;
        }
      //  sc2(p, ans);
        memset(f, -1, sizeof(f));
        FOR (k, p, maxi - 1) {
            tmp = 0;
            rep (i, n) {
                if (f[i] != -1) tmp += (++f[i]);
                else if (k >= e[i]) tmp += (f[i] = 1);
                else if (b[i][k] == 1) tmp += (f[i] = e[i] - k + 1);
                else if (b[i][k] == 0) tmp += e[i] - k - 1;
            }
            ans = min(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}




















