#include <bits/stdc++.h>

#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
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
#define ins insert

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

inline void scan(int &t) {
    int n = 0, s = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') s = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    t = n * s;
}

const int M = 131072;

int n, m;
int a[M * 2 + 1];

void init() {
    memset(a, 127, sizeof(a));
}

void update(int x, int y) {
    for (a[x += M] = y, x >>= 1; x; x >>= 1) {
        a[x] = min(a[x << 1], a[x << 1 | 1]);
    }
}

int gao(int s, int t) {
    int ans = ~0U >> 1;
    for (s = s + M - 1, t = t + M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
        if (~s & 1) ans = min(ans, a[s ^ 1]);
        if (t & 1) ans = min(ans, a[t ^ 1]);
    }
    return ans;
}

int main() {
    //file_r("in.txt");
    //file_w("out.txt");
    int x, y, z;
    while (~scanf("%d", &n)) {
        init();
        FOR (i, 1, n) {
            scan(x);
            update(i, x);
        }
        scan(m);
        while (m--) {
            scan(x), scan(y), scan(z);
            if (x == 1) update(y, z);
            else printf("%d\n", gao(y, z));
        }
    }
    return 0;
}

/*
6
4 5 6 2 1 3
4
1 3 5
2 1 4
1 1 9
2 2 6
*/
