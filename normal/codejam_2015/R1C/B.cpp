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

const int N = 105, CH = 26;

int e;
int chd[N][CH];
int wv[N], fail[N];
int q[N];

void init() {
    e = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    wv[0] = 0;
}

void add(char* str, int val) {
    int i, id, p = 0;
    for (i = 0; str[i]; i++) {
        id = str[i] - 'A';
        if (chd[p][id] == -1) {
            memset(chd[e], -1, sizeof(chd[e]));
            wv[e] = 0;
            chd[p][id] = e++;
        }
        p = chd[p][id];
    }
    wv[p] = val;
}

void build() {
    int i, p, v, head, tail;
    fail[0] = head = tail = 0;
    for (i = 0; i < CH; i++) {
        if (chd[0][i] != -1) {
            fail[chd[0][i]] = 0;
            q[tail++] = chd[0][i];
        } else chd[0][i] = 0;
    }
    while (head != tail) {
        p = q[head++];
        for (i = 0; i < CH; i++) {
            v = chd[p][i];
            if (v != -1) {
                fail[v] = chd[fail[p]][i];
                q[tail++] = v;
                //if (work[fail[v]] != 0) work[v] += work[fail[v]];
            } else chd[p][i] = chd[fail[p]][i];
        }
    }
}

int T;
int k, l, s;
char sk[N], sl[N];
double dp[2][N][N];
double p[CH];

void solve() {
    int now = 0, pre = 1;
    rep (i, CH) p[i] = 0;
    rep (i, k) p[sk[i] - 'A'] += 1;
    rep (i, CH) p[i] = p[i] / k;
    rep (i, )
}

int main() {
    int cas = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &k, &l, &s);
        scanf("%s", sk);
        scanf("%s", sl);
        init();
        add(sl, 1);
        build();
        solve();
    }
    return 0;
}
















