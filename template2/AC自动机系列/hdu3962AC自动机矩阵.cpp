#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

const int LEN = 10, NODE = 40, CH = 4, N = 10, L = 1000005, MOD = 10007, E = NODE * 3;

int n, m, end;
char s[LEN];
int work[NODE], chd[NODE][CH], fail[NODE], q[NODE];
int sw[256];
int dp[2][NODE][3];
int a[E][E], b[E][E], tmp[E][E];

void init() {
    end = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    work[0] = 0;
    sw['A'] = 0, sw['T'] = 1, sw['C'] = 2, sw['G'] = 3;
}

void add(char *str, int val) {
    int i, id, p = 0;
    for (i = 0; str[i]; i++) {
        id = sw[str[i]];
        if (chd[p][id] == -1) {
            memset(chd[end], -1, sizeof(chd[end]));
            work[end] = 0;
            chd[p][id] = end++;
        }
        p = chd[p][id];
    }
    work[p] = val;
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
                work[v] += work[fail[v]];
            } else chd[p][i] = chd[fail[p]][i];
        }
    }
}

void mul(int a[E][E], int b[E][E], int e) {
    int i, j, k;
    memset(tmp, 0, sizeof(tmp));
    for (i = 0; i < e; i++) {
        for (k = 0; k < e; k++) {
            if (a[i][k] == 0) continue;
            for (j = 0; j < e; j++) {
                if (b[k][j] == 0) continue;
                tmp[i][j] += a[i][k] * b[k][j];
                tmp[i][j] %= MOD;
            }
        }
    }
}

void solve() {
    int i, j, k, h, u, v, sum, e = 3 * end, ans = 0;
    memset(a, 0, sizeof(a));
    for (i = 0; i < end; i++) {
        for (j = 0; j < 3; j++) {
            u = i + j * end;
            for (k = 0; k < CH; k++) {
                h = chd[i][k];
                sum = j + work[h];
                sum = sum > 2 ? 2 : sum;
                v = h + sum * end;
                a[u][v]++;
            }
        }
    }
    memset(b, 0, sizeof(b));
    for (i = 0; i < e; i++) b[i][i] = 1;
    while (m) {
        if (m & 1) {
            mul(b, a, e);
            memcpy(b, tmp, sizeof(tmp));
        }
        mul(a, a, e);
        memcpy(a, tmp, sizeof(tmp));
        m >>= 1;
    }
    for (i = 2 * end; i < e; i++) {
        ans += b[0][i];
        ans %= MOD;
    }
    printf("%d\n", ans);
}

int main() {
    int i, j;
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        for (i = 1; i <= n; i++) {
            scanf("%s", s);
            add(s, 1);
        }
        build();
        solve();
    }
    return 0;
}
