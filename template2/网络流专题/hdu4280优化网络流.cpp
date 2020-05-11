#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))

using namespace std;
int chh;

const int VM = 100010, EM = 400010, inf = 0x3f3f3f3f;

struct E {
    int to, frm, nxt, cap;
} edge[EM];

int n, m, e, src, des;
int head[VM], dep[VM], gap[VM];

void add_edge(int cu, int cv, int cw) {
    edge[e].frm = cu;
    edge[e].to = cv;
    edge[e].cap = cw;
    edge[e].nxt = head[cu];
    head[cu] = e++;
    edge[e].frm = cv;
    edge[e].to = cu;
    edge[e].cap = 0;
    edge[e].nxt = head[cv];
    head[cv] = e++;
}

int que[VM];

void BFS() {
    int front = 0, rear = 0, u, v;
    memset(dep, -1, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    gap[0] = 1;
    dep[des] = 0;
    que[rear++] = des;
    while (front != rear) {
        u = que[front++];
        front = front % VM;
        for (int i = head[u]; i != -1; i = edge[i].nxt) {
            v = edge[i].to;
            if (edge[i].cap != 0 || dep[v] != -1)
                continue;
            que[rear++] = v;
            rear = rear % VM;
            ++gap[dep[v] = dep[u] + 1];
        }
    }
}

int cur[VM], stack[VM];

int sap() {     //sap模板
    int u = src, res = 0, top = 0, i;
    memcpy(cur, head, sizeof(head));
    BFS();
    while (dep[src] < n) {
        if (u == des) {
            int temp = inf, inser = n;
            for (i = 0; i != top; ++i) {
                if (temp > edge[stack[i]].cap) {
                    temp = edge[stack[i]].cap;
                    inser = i;
                }
            }
            for (i = 0; i != top; ++i) {
                edge[stack[i]].cap -= temp;
                edge[stack[i]^1].cap += temp;
            }
            res += temp;
            top = inser;
            u = edge[stack[top]].frm;
        }

        if (u != des && gap[dep[u] -1] == 0) break;
        for (i = cur[u]; i != -1; i = edge[i].nxt) {
            if (edge[i].cap != 0 && dep[u] == dep[edge[i].to] + 1) break;
        }
        if (i != -1) {
            cur[u] = i;
            stack[top++] = i;
            u = edge[i].to;
        } else {
            int min = n;
            for (i = head[u]; i != -1; i = edge[i].nxt) {
                if (edge[i].cap == 0) continue;
                if (min > dep[edge[i].to]) {
                    min = dep[edge[i].to];
                    cur[u] = i;
                }
            }
            --gap[dep[u]];
            ++gap[dep[u] = min + 1];
            if (u != src) u = edge[stack[--top]].frm;
        }
    }
    return res;
}

void init(int SRC, int DES) {
    e = 0, src = SRC, des = DES;
    memset(head, -1, sizeof(head));
}

inline void in(int &t) {
    int n = 0, s = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') s = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    t = n * s;
}

int T;

int main() {
    int i, j, p1, p2, x1, x2, x, y, u, v, w;
    in(T);
    while (T--) {
        in(n), in(m);
        p1 = p2 = -1;
        for (i = 1; i <= n; i++) {
            in(x), in(y);
            if (p1 == -1 || x < x1) p1 = i, x1 = x;
            if (p2 == -1 || x > x2) p2 = i, x2 = x;
        }
        init(p1, p2);
        for (i = 1; i <= m; i++) {
            in(u), in(v), in(w);
            add_edge(u, v, w), add_edge(v, u, w);
        }
        printf("%d\n", sap());
    }
    return 0;
}
