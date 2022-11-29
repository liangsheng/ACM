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

const int N = 100005, CH = 26;

int e, last;
int chd[N << 1][CH], fail[N << 1], wv[N << 1], c[N << 1], h[N << 1];

void init() {
    e = 1, last = 0;
    memset(chd[0], -1, sizeof(chd[0]));
    wv[0] = 0, fail[0] = -1;
}

void add(char ch) {
    int np, p, q, nq, id = ch - 'a';
    memset(chd[e], -1, sizeof(chd[e]));
    wv[e] = c[e] = wv[last] + 1, np = e++;
    p = last, last = np;
    for (; p != -1 && chd[p][id] == -1; p = fail[p]) chd[p][id] = np;
    if (p == -1) fail[np] = 0;
    else {
        q = chd[p][id];
        if (wv[q] == wv[p] + 1) fail[np] = q;
        else {
            memset(chd[e], -1, sizeof(chd[e]));
            wv[e] = c[e] = wv[p] + 1, nq = e++;
            memcpy(chd[nq], chd[q], sizeof(chd[q]));
            fail[nq] = fail[q];
            fail[q] = fail[np] = nq;
            for (; p != -1 && chd[p][id] == q; p = fail[p]) chd[p][id] = nq;
        }
    }
}

int n;
int dws[N << 1], b[N << 1];
char s[N];

int main() {
    file_r("in.txt");
    int i, j, p, tmp, ans;
    init();
    scanf("%s", s);
    n = strlen(s);
    for (i = 0; s[i]; i++) add(s[i]);
    memset(dws, 0, sizeof(dws));
    for (i = 0; i < e; i++) dws[wv[i]]++;
    for (i = 1; i <= n; i++) dws[i] += dws[i - 1];
    for (i = 0; i < e; i++) b[--dws[wv[i]]] = i;
    while (~scanf("%s", s)) {
        for (tmp = p = i = 0; s[i]; i++) {
            j = s[i] - 'a';
            if (chd[p][j] != -1) tmp++, p = chd[p][j];
            else {
                for (; p != -1 && chd[p][j] == -1; p = fail[p]);
                if (p == -1) p = 0, tmp = 0;
                else tmp = wv[p] + 1, p = chd[p][j];
            }
            if (tmp > h[p]) h[p] = tmp;
        }
        for (i = e - 1; i >= 0; i--) {
            j = b[i];
            if (h[j] < c[j]) c[j] = h[j];
            //if (h[j] > h[fail[j]]) h[fail[j]] = h[j];
            if (h[j] > 0) h[fail[j]] = wv[fail[j]];
            h[j] = 0;
        }
    }
    ans = 0;
    for (i = 0; i < e; i++) ans = max(ans, c[i]);
    printf("%d\n", ans);
    return 0;
}
