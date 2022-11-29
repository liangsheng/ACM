#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))

using namespace std;
int chh;

typedef long long LL;

const int N = 100005, CH = 26;

int e, last;
int chd[N << 1][CH], fail[N << 1], wv[N << 1], wu[N << 1], c[N << 1];

void init() {
    e = 1, last = 0;
    memset(chd[0], -1, sizeof(chd[0]));
    wv[0] = 0, fail[0] = -1;
}

void add(char ch) {
    int np, p, q, nq, id = ch - 'a';
    memset(chd[e], -1, sizeof(chd[e]));
    wv[e] = wv[last] + 1, np = e++;
    p = last, last = np;
    for (; p != -1 && chd[p][id] == -1; p = fail[p]) chd[p][id] = np;
    if (p == -1) fail[np] = 0;
    else {
        q = chd[p][id];
        if (wv[q] == wv[p] + 1) fail[np] = q;
        else {
            memset(chd[e], -1, sizeof(chd[e]));
            wv[e] = wv[p] + 1, nq = e++;
            memcpy(chd[nq], chd[q], sizeof(chd[q]));
            fail[nq] = fail[q];
            fail[q] = fail[np] = nq;
            for (; p != -1 && chd[p][id] == q; p = fail[p]) chd[p][id] = nq;
        }
    }
}

int T, n;
int dws[N << 1], b[N << 1];
char s[N];

void build() {
    int i, j, k, len = strlen(s);
    memset(dws, 0, sizeof(dws));
    for (i = 0; i < e; i++) dws[wv[i]]++;
    for (i = 1; i <= len; i++) dws[i] += dws[i - 1];
    for (i = 0; i < e; i++) b[--dws[wv[i]]] = i;
    for (i = 1; i < e; i++) wu[i] = wv[fail[i]] + 1;
    for (i = 0; i < CH; i++) {
        if (chd[0][i] == -1) chd[0][i] = 0;
    }
    for (k = 1; k < e; k++) {
        i = b[k];
        for (j = 0; j < CH; j++) {
            if (chd[i][j] != -1) continue;
            if (chd[fail[i]][j] > 0) chd[i][j] = -fail[i];
            else chd[i][j] = chd[fail[i]][j];
        }
    }
}

int main() {
    int i, j, k, p, cas = 0, tmp;
    LL ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        scanf("%s", s);
        for (i = 0; s[i]; i++) add(s[i]);
        build();
        memset(c, 0, sizeof(c));
        for (k = 1; k <= n; k++) {
            scanf("%s", s);
            for (p = tmp = i = 0; s[i]; i++) {
                j = s[i] - 'a';
                if (chd[p][j] > 0) tmp++, p = chd[p][j];
                else if (chd[p][j] == 0) {
                    if (chd[0][j] > 0) tmp = 1, p = chd[0][j];
                    else tmp = 0, p = 0;
                } else {
                    tmp = wv[-chd[p][j]] + 1;
                    p = chd[-chd[p][j]][j];
                }
                c[p] = max(c[p], tmp);
            }
        }
        for (i = e - 1; i >= 0; i--) {
            j = b[i];
            if (c[j] > 0) c[fail[j]] = wv[fail[j]];
        }
        ans = 0LL;
        for (i = 1; i < e; i++) {
            tmp = min(wv[i] - c[i], wv[i] - wu[i] + 1);
            ans += (LL) tmp;
        }
        printf("Case %d: %lld\n", ++cas, ans);
    }
    return 0;
}
