/*
题意：求一个割边最少的最小割集的边数。

思路：经典问题，做法有很多，说说翅膀的思路吧。要求边最少，则对原边重新赋权，若原容量
为c，则新容量为w=1+M*c （M为一个比边数E大的数），再新图上用Dinic求maxflow，则原图最小
割的容量为maxflow/M，最小割边数为maxflow%M，因为重新赋权不会改变流对边的选择，而w中1
的个数也不会超过M，所以统计1的个数就能求出最小割边数。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

typedef long long LL;

const LL N = 1005, M = 400005, MOD = 100001, INF = ~0U >> 2;

struct Node {
    LL v, w, next;
} edge[M];

LL e, s, t, NN;
LL head[N], pre[N], cur[N], dis[N], gap[N];

void init(LL S, LL T, LL cnt) {
    e = 0, s = S, t = T, NN = cnt;
    fill(head, head + cnt + 1, -1);
}

void add_edge(LL u, LL v, LL w) {
    edge[e].v = v, edge[e].w = w;
    edge[e].next = head[u], head[u] = e++;
    edge[e].v = u, edge[e].w = 0;
    edge[e].next = head[v], head[v] = e++;
}

LL sap() {
    LL i, flow = 0, aug = INF, u, v;
    bool flag;
    for (i = 0; i <= NN; i++) {
        cur[i] = head[i];
        gap[i] = dis[i] = 0;
    }
    gap[0] = NN;
    u = pre[s] = s;
    while (dis[s] < NN) {
        flag = 0;
        for (LL &j = cur[u]; j != -1; j = edge[j].next) {
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
        LL mindis = NN;
        for (LL j = head[u]; j != -1; j = edge[j].next) {
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

LL T, n, m;

int main() {
    LL i, j, u, v, w, d, ans, cas = 0;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld %lld", &n, &m);
        init(0, n - 1, n);
        for (i = 1; i <= m; i++) {
            scanf("%lld %lld %lld %lld", &u, &v, &w, &d);
            add_edge(u, v, w * MOD + 1);
            if (d) add_edge(v, u, w * MOD + 1);
        }
        ans = sap() % MOD;
        printf("Case %lld: %lld\n", ++cas, ans);
    }
    return 0;
}
