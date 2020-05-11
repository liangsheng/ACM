#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

const int N = 150, M = N * N * 2, INF = ~0U >> 2;

struct Node {
    int v, w, next;
} edge[M], h[M];

int e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];

void init(int S, int T, int cnt) {
    e = 0, s = S, t = T, NN = cnt;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w) {
    h[e].v = v, h[e].w = w;
    h[e].next = head[u], head[u] = e++;
    h[e].v = u, h[e].w = 0;
    h[e].next = head[v], head[v] = e++;
}

int sap() {
    int i, flow = 0, aug = INF, u, v;
    bool flag;
    for (i = 0; i <= NN; i++) {
        cur[i] = head[i];
        gap[i] = dis[i] = 0;
    }
    gap[0] = NN;
    u = pre[s] = s;
    while (dis[s] < NN) {
        flag = 0;
        for (int &j = cur[u]; j != -1; j = edge[j].next) {
            v = edge[j].v;
            if (edge[j].w > 0 && dis[u] == dis[v] + 1) {
                flag = 1;
                if (edge[j].w < aug) aug = edge[j].w;
                pre[v] = u;
                u = v;
                if (u == t) {
                    flow += aug;
                    while (u != s) {
                        u = pre[u];
                        edge[cur[u]].w -= aug;
                        edge[cur[u] ^ 1].w += aug;
                    }
                    aug = INF;
                }
                break;
            }
        }
        if (flag) continue;
        int mindis = NN;
        for (int j = head[u]; j != -1; j = edge[j].next) {
            v = edge[j].v;
            if (edge[j].w > 0 && dis[v] < mindis) {
                mindis = dis[v];
                cur[u] = j;
            }
        }
        if ((--gap[dis[u]]) == 0) break;
        gap[dis[u] = mindis + 1]++;
        u = pre[u];
    }
    return flow;
}

int T;
int w[15], id[15][15], f[15][15];
char str[50];

int main() {
    int i, j, k, n, v, tmp, sum, ans;
    bool a[15];
    scanf("%d", &T);
    while (T--) {
        n = 0;
        gets(str);
        while (strlen(str) == 0) gets(str);
        for (i = 0; i < strlen(str); i++) {
            if (str[i] >= '0' && str[i] <= '9') w[++n] = str[i] - '0';
        }
        tmp = n * (n - 1) / 2 + n + 1;
        init(0, tmp, tmp + 1);
        tmp = n;
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) id[i][j] = id[j][i] = ++tmp;
        }
        for (i = 1; i <= n; i++) add_edge(s, i, w[i]);
        for (i = n + 1; i < t; i++) add_edge(i, t, 1);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (j == i) continue;
                tmp = id[i][j];
                f[i][j] = e;
                add_edge(i, tmp, 1);
            }
        }
        tmp = 1 << (n - 1);
        for (i = n - 1; i >= 1; i--) {
            if (w[i] != w[i + 1]) break;
            tmp |= 1 << (i - 1);
        }
        ans = 0;
        for (i = tmp; i < (1 << n); i++) {
            sum = 0;
            fill(a + 1, a + n + 1, 0);
            for (j = 1; j <= n; j++) a[j] = (i >> (j - 1)) & 1;
            for (j = 1; j <= n; j++) {
                if (!a[j]) continue;
                sum++;
            }
            memcpy(edge, h, sizeof(edge));
            for (j = 1; j < n; j++) {
                if (!a[j]) continue;
                if (w[j] == w[n]) continue;
                for (k = j + 1; k <= n; k++) {
                    if (w[k] == w[j]) continue;
                    v = f[k][j];
                    edge[v].w = edge[v + 1].w = 0;
                }
            }
            v = sap();
            if (v == n * (n - 1) / 2) ans = max(ans, sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}
