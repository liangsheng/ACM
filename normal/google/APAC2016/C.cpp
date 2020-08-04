#include <bits/stdc++.h>

#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
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
#define sqr(x) ((x) * (x))

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 10000 * 32 + 5, CH = 2;

int T, n, e;
int chd[N][2], wv[N];

void init() {
    e = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    wv[0] = 0;
}

void add(int x0, int x1, int x2, int x3, int x4) {
    int p = 0, m = x4, id;
    //sc(x4);
    FORD (i, 7, 0) {
        if (m <= 0) break;
        m--;
        id = (x0 >> i) & 1;
        if (chd[p][id] == -1) {
            memset(chd[e], -1, sizeof(chd[e]));
            wv[e] = 0;
            chd[p][id] = e++;
        }
        p = chd[p][id];
    }

    FORD (i, 7, 0) {
        if (m <= 0) break;
        m--;
        id = (x1 >> i) & 1;
        if (chd[p][id] == -1) {
            memset(chd[e], -1, sizeof(chd[e]));
            wv[e] = 0;
            chd[p][id] = e++;
        }
        p = chd[p][id];
    }

    FORD (i, 7, 0) {
        if (m <= 0) break;
        m--;
        id = (x2 >> i) & 1;
        if (chd[p][id] == -1) {
            memset(chd[e], -1, sizeof(chd[e]));
            wv[e] = 0;
            chd[p][id] = e++;
        }
        p = chd[p][id];
    }

    FORD (i, 7, 0) {
        if (m <= 0) break;
        m--;
        id = (x3 >> i) & 1;
        if (chd[p][id] == -1) {
            memset(chd[e], -1, sizeof(chd[e]));
            wv[e] = 0;
            chd[p][id] = e++;
        }
        p = chd[p][id];
    }
    wv[p] = 1;
    //cout << "FF " << wv[8] << '\n';
}

void dfs(int p) {
    if (wv[p] == 1) return ;
    int l = chd[p][0], r = chd[p][1];
    if (l != -1) dfs(l);
    if (r != -1) dfs(r);
    if (l != -1 && wv[l] && r != -1 && wv[r]) wv[p] = 1;
    else wv[p] = 0;
}

void nb(string s) {
    int x0 = 0, x1 = 0, x2 = 0, x3 = 0, x4 = s.size();
    FOR (i, x4, 31) s.pb('0');
    FOR (i, 0, 7) x0 = x0 * 2 + (s[i] == '1');
    FOR (i, 8, 15) x1 = x1 * 2 + (s[i] == '1');
    FOR (i, 16, 23) x2 = x2 * 2 + (s[i] == '1');
    FOR (i, 24, 31) x3 = x3 * 2 + (s[i] == '1');
    printf("%d.%d.%d.%d\/%d\n", x0, x1, x2, x3, x4);
}

void gao(int p, string s) {
    //sc3(p, s, wv[p]);
    if (wv[p] == 1) {
        nb(s);
        return ;
    }
    int l = chd[p][0], r = chd[p][1];
    if (l != -1) gao(l, s + "0");
    if (r != -1) gao(r, s + "1");
}

int main() {
    file_r("C-large-practice.in");
    file_w("C.out");
    int cas = 0, x0, x1, x2, x3, x4;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        rep (i, n) {
            scanf("%d.%d.%d.%d/%d", &x0, &x1, &x2, &x3, &x4);
            add(x0, x1, x2, x3, x4);
            //cout << "e= " << e << '\n';
        }
        printf("Case #%d:\n", ++cas);
        //sc(e);
        dfs(0);
        //sc(wv[8]);
        gao(0, "");
    }
    return 0;
}
