#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))
#define rep(i, n) for (int i = 0; i <= n; i++)

using namespace std;
int chh;

const int V = 65, E = 6000, INF = 1e7;

struct NODE {
    int u, v, flow, cost;
    int next;
};

int s, t, e;
int head[V], pre[V], visit[V], dis[V];
NODE edge[E];

void add_edge(int u, int v, int flow, int cost) {
    //printf("s= %d %d %d %d", u, v, flow, cost), pause;
    edge[e].u = u;
    edge[e].v = v;
    edge[e].flow = flow;
    edge[e].cost = cost;
    edge[e].next = head[u];
    head[u]=e++;
    edge[e].u=v;
    edge[e].v=u;
    edge[e].flow=0;
    edge[e].cost=-cost;
    edge[e].next=head[v];
    head[v]=e++;
}

void SPFA() {
    int i, k, front;
    queue<int> q;
    memset(pre, -1, sizeof(pre));
    memset(visit, 0, sizeof(visit));
    for (i = s; i <= t; i++) dis[i] = INF;
    dis[s] = 0;
    q.push(s);
    visit[s] = 1;
    while (!q.empty()) {
        front = q.front();
        visit[front] = 0;
        for (i = head[front]; i != -1; i = edge[i].next) {
            k = edge[i].v;
            if (edge[i].flow > 0 && dis[front] + edge[i].cost < dis[k]) {
                dis[k] = dis[front] + edge[i].cost;
                pre[k] = i;
                if (visit[k] == 0) {
                    visit[k] = 1;
                    q.push(k);
                }
            }
        }
        q.pop();
    }
}

int min_cost() {
    int i, j, ans = 0, mmin;
    while (1) {
        SPFA();
        if (pre[t] == -1) break;
        mmin = INF;
        for (i = t; i != s; i = edge[pre[i]].u)
            if (edge[pre[i]].flow < mmin) mmin = edge[pre[i]].flow;
        for (i = t; i != s; i = edge[pre[i]].u) {
            edge[pre[i]].flow -= mmin;
            edge[pre[i] ^ 1].flow += mmin;
        }
        ans += dis[t]*mmin;
    }
    return ans;
}

void init(int ss, int tt) {
    e = 0, s = ss, t = tt;
    memset(head, -1, sizeof(head));
}

const int N = 45, M = 25;

int day, maxi, cou;
int cre[M], gra[M], h[105];

int main() {
    int i, j, tmp, sum;
    char ch;
    bool flag;
    double ans;
    memset(h, 0, sizeof(h));
    for (i = 60; i <= 100; i++) h[i] = 1600 * 4 - 3 * (100 - i) * (100 - i);
    while (~scanf("%d %d %d", &day, &maxi, &cou)) {
        if (day == 0 && maxi == 0 && cou == 0) break;
        sum = 0;
        for (i = 1; i <= cou; i++) scanf("%d", &cre[i]), sum += cre[i];
        for (i = 1; i <= cou; i++) scanf("%d", &gra[i]);
        init(0, day + cou + 1);
        for (i = 1; i <= day; i++) add_edge(i + cou, t, maxi, 0);
        for (i = 1; i <= day; i++) {
            for (j = 1; j <= cou; j++) {
                ch = getchar();
                while (ch != '0' && ch != '1') ch = getchar();
                if (ch == '1') add_edge(j, i + cou, INF, 0);
            }
        }
        for (j = 1; j <= cou; j++) {
            tmp = gra[j];
            if (tmp < 60) {
                add_edge(s, j, 60 - tmp, -INF);
                tmp = 60;
            }
            for (i = tmp + 1; i <= 100; i++) {
                add_edge(s, j, 1, (h[i - 1] - h[i]) * cre[j]);
            }
        }
        min_cost();
        for (i = head[s]; i != -1; i = edge[i].next) {
            gra[edge[i].v] += edge[i ^ 1].flow;
        }
        flag = 1;
        for (j = 1; j <= cou && flag; j++) {
            if (gra[j] < 60) flag = 0;
        }
        if (!flag) puts("0.000000");
        else {
            tmp = 0;
            for (j = 1; j <= cou; j++) tmp += h[gra[j]] * cre[j];
            ans = (double) tmp / (sum * 1600);
            printf("%.6lf\n", ans + 1e-8);
        }
    }
    return 0;
}
