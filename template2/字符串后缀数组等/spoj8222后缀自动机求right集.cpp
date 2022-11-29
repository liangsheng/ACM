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

const int N = 250005, CH = 26;

int e, last;
int chd[N << 1][CH], fail[N << 1], wv[N << 1], c[N << 1];

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

int n;
int dws[N << 1], b[N << 1], f[N];
char s[N];

void build() {
    int i, len;
    memset(dws, 0, sizeof(dws));
    len = strlen(s);
    for (i = 0; i < e; i++) dws[wv[i]]++;
    for (i = 1; i <= len; i++) dws[i] += dws[i - 1];
    for (i = 0; i < e; i++) b[--dws[wv[i]]] = i;
}

int main() {
    int i, j, p;
    while (~scanf("%s", s)) {
        init();
        for (i = 0; s[i]; i++) add(s[i]);
        build();
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        for (p = i = 0; s[i]; i++) {
            p = chd[p][s[i] - 'a'];
            c[p]++;
        }
        for (i = e - 1; i >= 1; i--) {
            j = b[i];
            c[fail[j]] += c[j];
            f[wv[j]] = max(f[wv[j]], c[j]);
        }
        n = strlen(s);
        for (i = n - 1; i >= 1; i--) f[i] = max(f[i], f[i + 1]);
        for (i = 1; i <= n; i++) printf("%d\n", f[i]);
    }
    return 0;
}
