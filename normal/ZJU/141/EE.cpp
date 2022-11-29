#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define ins insert
#define rb rbegin
#define be begin
#define er erase
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)

#define sc(x) cout << #x" = " << x << endl, system("pause")
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, system("pause")
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, system("pause")
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, system("pause")

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 205, M = N * N * 2, INF = 1e7;

struct NODE {
    int u, v, flow, cost;
    int next;
};

int s, t, e, flow;
int head[N], pre[N], visit[N], dis[N];
NODE edge[M];

void init(int S, int T) {
    e = 0, s = S, t = T, flow = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int flow, int cost) {
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
        flow += mmin;
    }
    return ans;
}

int nn, m;
int a[N], b[N], g[N][N];

int main() {
    int x, y, sum, gg;
    while (~scanf("%d %d", &nn, &m)) {
        sum = gg = 0;
        FOR (i, 1, nn) scanf("%d", &a[i]), sum += a[i];
        FOR (i, 1, nn) scanf("%d", &b[i]), gg += b[i];
        FOR (i, 1, nn) {
            FOR (j, 1, nn) g[i][j] = INF;
            g[i][i] = 0;
        }
        FOR (i, 1, m) {
            scanf("%d %d", &x, &y);
            g[x][y] = g[y][x] = 1;
        }
        if (gg != sum) {
            puts("-1");
            continue;
        }
        FOR (k, 1, nn) FOR (i, 1, nn) FOR (j, 1, nn) {
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
        init(0, 2 * nn + 1);
        FOR (i, 1, nn) add_edge(s, i, a[i], 0);
        FOR (i, 1, nn) add_edge(i + nn, t, b[i], 0);
        FOR (i, 1, nn) FOR (j, 1, nn) {
            if (g[i][j] == INF) continue;
            add_edge(i, j + nn, INF, g[i][j]);
        }
        int ans = min_cost();
        //cout << "flow= " << flow << '\n';
        if (flow != sum) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}











