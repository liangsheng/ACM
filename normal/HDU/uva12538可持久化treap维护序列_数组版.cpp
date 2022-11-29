#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3000005, INF = ~0U >> 1;

int n, tot, cnt, d;
int sz[N], L[N], R[N], rt[N];
char s[N], v[N];

void init() {
    tot = 0;         //num of node
    cnt = 0;         //version
    d = 0;           //for uva12538
}

void update(int k) {
    sz[k] = sz[L[k]] + sz[R[k]] + 1;
}

int cp(int k) {
    sz[++tot] = sz[k], v[tot] = v[k];
    L[tot] = L[k], R[tot] = R[k];
    return tot;
}

double weight() {
    int i = rand(), j = rand();
    if (i > j) swap(i, j);
    return double (i) / double (j);
}

void build(int l, int r, int &y) {
    if (l > r) return ;
    int mid = (l + r) >> 1;
    y = ++tot;
    v[y] = s[mid], sz[y] = 1;
    if (l == r) return ;
    build(1, mid - 1, L[y]);
    build(mid + 1, r, R[y]);
    update(y);
}

void split(int x, int y, int &l, int &r) {
    if (sz[x] <= y) {
        l = x, r = 0;
        return ;
    }
    int i, j, k = cp(x);
    if (y <= sz[L[k]]) {
        split(L[k], y, i, j);
        L[k] = j, l = i, r = k;
    } else {
        split(R[k], y - sz[L[k]], i, j);
        R[k] = i, l = k, r = j;
    }
    update(k);
}

int link(int x, int y) {
    if (!x || !y) return x + y;
    int k;
    double i = weight(), j = double (sz[x]) / double (sz[x] + sz[y]);
    if (i < j) {
        k = cp(x);
        R[k] = link(R[k], y);
    } else {
        k = cp(y);
        L[k] = link(x, L[x]);
    }
    update(k);
    return k;
}

void print(int x) {
    if (!x) return ;
    print(L[x]);
    if (v[x] == 'c') d++;      //for uva12538
    printf("%c", v[x]);
    print(R[x]);
}

int main() {
    int p, op, v, c, l, t1, t2, t3, t4;
    while (~scanf("%d", &n)) {
        init();
        while (n--) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d %s", &p, s + 1);
                p -= d, l = strlen(s + 1);
                build(1, l, rt[++cnt]);
                if (!p) rt[cnt] = link(rt[cnt], rt[cnt - 1]);
                else if (p == sz[rt[cnt - 1]]) rt[cnt] = link(rt[cnt - 1], rt[cnt]);
                else {
                    split(rt[cnt - 1], p, t1, t2);
                    t2 = link(rt[cnt], t2);
                    rt[cnt] = link(t1, t2);
                }
            } else if (op == 2) {
                scanf("%d %d", &p, &c);
                p -= d, c -= d;
                split(rt[cnt], p - 1, t1, t2);
                split(t2, c, t3, t4);
                rt[++cnt] = link(t1, t2);
            } else {
                scanf("%d %d %d", &v, &p, &c);
                v -= d, p -= d, c -= d;
                split(rt[v], p - 1, t1, t2);
                split(t2, c, t3, t4);
                print(t3);
                puts("");
            }
        }
    }
    return 0;
}
