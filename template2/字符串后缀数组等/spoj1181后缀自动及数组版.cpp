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
int chd[N << 1][CH], fail[N << 1], wv[N << 1];

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

char s[N];

int main() {
    int i, j, p, ans, tmp;
    while (~scanf("%s", s)) {
        init();
        for (i = 0; s[i]; i++) add(s[i]);
        scanf("%s", s);
        ans = tmp = 0;
        for (i = 0, p = 0; s[i]; i++) {
            j = s[i] - 'a';
            if (chd[p][j] != -1) tmp++, p = chd[p][j];
            else {
                for (; p != -1 && chd[p][j] == -1; p = fail[p]);
                if (p == -1) p = 0, tmp = 0;
                else tmp = wv[p] + 1, p = chd[p][j];
            }
            ans = max(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
