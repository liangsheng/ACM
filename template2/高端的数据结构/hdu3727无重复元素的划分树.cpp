#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

typedef long long LL;

const int N = 100005, M = 20;

struct CMD {
    int ty;
    int s, t, k;
} p[210000];

int n, e;
int sorted[N];
int val[M][N], toleft[M][N];

void init(int k, int s, int t, int d) {
    int i, mid = (s + t) >> 1, midv = sorted[mid];
    int l = s, r = mid + 1, tmp = 0;
    for (i = s; i <= t; i++) {
        if (val[d][i] <= midv) {
            toleft[d][i] = tmp + 1;
            val[d + 1][l++] = val[d][i];
        }
        else {
            toleft[d][i] = tmp;
            val[d + 1][r++] = val[d][i];
        }
        tmp = toleft[d][i];
    }
    if (s == t) return;
    init(k << 1, s ,mid, d + 1);
    init(k << 1 | 1, mid + 1, t, d + 1);
}

int find1(int k, int s, int t, int d, int l, int r, int id) {
    int mid = (s + t) >> 1, ln, lnp, rn, rnp, nl, nr;
    if (s == t) return sorted[s];
    if (l == s) {
        ln = toleft[d][r];
        lnp = 0;
    } else {
        ln = toleft[d][r] - toleft[d][l - 1];
        lnp = toleft[d][l - 1];
    }
    if (ln >= id) {
        nl = s + lnp;
        nr = s + toleft[d][r] - 1;
        return find1(k << 1, s, mid, d + 1, nl, nr, id);
    } else {
        rn = r - l + 1 - ln;
        rnp = l - s - lnp;
        nl = mid + 1 + rnp;
        nr = mid + rn + rnp;
        return find1(k << 1 | 1, mid + 1, t, d + 1, nl, nr, id - ln);
    }
}

int find2(int k, int s, int t, int d, int r, int v) {
    int mid = (s + t) >> 1, midv = sorted[mid], ln, nr;
    ln = toleft[d][r];
    if (midv == v) return ln;
    if (midv > v) {
        nr = s + toleft[d][r] - 1;
        return find2(k << 1, s, mid, d + 1, nr, v);
    } else {
        nr = mid + r - s + 1 - ln;
        return ln + find2(k << 1, mid + 1, t, d + 1, nr, v);
    }
}

int main() {
    int i, j, cnt, cas = 0;
    char s[8];
    LL ans1, ans2, ans3;
    while (scanf("%d", &n) != EOF) {
        e = 0;
        for (i = 1; i <= n; i++) {
            scanf("%s", s);
            if (s[0] == 'I') {
                p[i].ty = 0;
                scanf("%d", &p[i].k);
                sorted[++e] = p[i].k;
                val[0][e] = p[i].k;
            } else if (s[6] == '1') {
                p[i].ty = 1;
                scanf("%d %d %d", &p[i].s, &p[i].t, &p[i].k);
            } else if (s[6] == '2') {
                p[i].ty = 2;
                scanf("%d", &p[i].k);
            } else {
                p[i].ty = 3;
                scanf("%d", &p[i].k);
            }
        }
        sort(sorted + 1, sorted + e + 1);
        init(1, 1, e, 0);
        ans1 = ans2 = ans3 = cnt = 0;
        for (i = 1; i <= n; i++) {
            if (p[i].ty == 0) cnt++;
            else if (p[i].ty == 1) {
                ans1 += find1(1, 1, e, 0, p[i].s, p[i].t, p[i].k);
            } else if (p[i].ty == 2) {
                ans2 += find2(1, 1, e, 0, cnt, p[i].k);
            } else {
                ans3 += find1(1, 1, e, 0, 1, cnt, p[i].k);
            }
        }
        printf("Case %d:\n%lld\n%lld\n%lld\n", ++cas, ans1, ans2, ans3);
    }
    return 0;
}
