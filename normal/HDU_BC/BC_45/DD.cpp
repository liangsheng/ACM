#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 200005;

int tc, n, q, op, x, y, res;

int u[maxn], v[maxn];

struct Node {
    int key, lc, rc, f, size, xorsum, rev;
} t[maxn];

void _rev(int x) {
    if (!x) return;
    swap(t[x].lc, t[x].rc);
    t[x].rev ^= 1;
}

void down(int x) {
    if (t[x].rev) {
        _rev(t[x].lc);
        _rev(t[x].rc);
        t[x].rev = 0;
    }
}

void up(int x) {
    if (!x) return;
    t[x].size = 1;
    t[x].xorsum = t[x].key;
    if (t[x].lc) {
        t[x].size += t[t[x].lc].size;
        t[x].xorsum ^= t[t[x].lc].xorsum;
    }
    if (t[x].rc) {
        t[x].size += t[t[x].rc].size;
        t[x].xorsum ^= t[t[x].rc].xorsum;
    }
}

bool isroot(int x) {
    int f = t[x].f;
    return (!f || t[f].lc != x && t[f].rc != x);
}

void leftrotate(int x) {
    int y = t[x].f;
    t[y].rc = t[x].lc;
    if (t[x].lc) t[t[x].lc].f = y;
    t[x].f = t[y].f;
    if (t[y].f) {
        if (t[t[y].f].lc == y) t[t[y].f].lc = x;
        if (t[t[y].f].rc == y) t[t[y].f].rc = x;
    }
    t[x].lc = y;
    t[y].f = x;
    up(y);
}

void rightrotate(int x) {
    int y = t[x].f;
    t[y].lc = t[x].rc;
    if (t[x].rc) t[t[x].rc].f = y;
    t[x].f = t[y].f;
    if (t[y].f) {
        if (t[t[y].f].lc == y) t[t[y].f].lc = x;
        if (t[t[y].f].rc == y) t[t[y].f].rc = x;
    }
    t[x].rc = y;
    t[y].f = x;
    up(y);
}

void splay(int x) {
    down(x);
    while (!isroot(x)) {
        int y = t[x].f, z = t[y].f;
        if (isroot(y)) {
            down(y);
            down(x);
            if (t[y].lc == x)
                rightrotate(x);
            else
                leftrotate(x);
        } else {
            down(z);
            down(y);
            down(x);
            if (t[y].lc == x)
                if (t[z].lc == y)
                    rightrotate(y), rightrotate(x);
                else
                    rightrotate(x), leftrotate(x);
            else if (t[z].lc == y)
                leftrotate(x), rightrotate(x);
            else
                leftrotate(y), leftrotate(x);
        }
    }
    up(x);
}

void access(int v) {
    for (int u = v, v = 0; u; v = u, u = t[u].f)
        splay(u), t[u].rc = v;
}

void evert(int v) {
    access(v);
    splay(v);
    _rev(v);
}

int findroot(int v) {
    access(v);
    splay(v);
    for (; t[v].lc; v = t[v].lc);
    splay(v);
    return v;
}

void link(int u, int v) {
    evert(u);
    t[u].f = v;
}

void cut(int u, int v) {
    evert(u);
    access(v);
    splay(v);
    t[u].f = t[v].lc = 0;
}

void change(int u, int v) {
    evert(u);
    t[u].key = v;
    up(u);
}

int query(int u, int v) {
    evert(u);
    access(v);
    splay(v);
    return t[v].xorsum;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d", &tc);
    while (tc --) {
        scanf("%d%d", &n, &q);
        for (int i = 1; i < n; i ++) scanf("%d%d", &u[i], &v[i]);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &t[i].key);
            t[i].key ++;
            t[i].lc = t[i].rc = t[i].f = t[i].rev = 0;
            up(i);
        }
        for (int i = 1; i < n; i ++) link(u[i], v[i]);
        while (q --) {
            scanf("%d%d%d", &op, &x, &y);
            if (op == 0) change(x, y + 1);
            else {
                res = query(x, y);
                if (res == 0) puts("-1");
                else printf("%d\n", res - 1);
            }
        }
    }
    return 0;
}
