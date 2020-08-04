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
#define sqr(r) ((LL) (r) * (r))
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

const int N = 2005, M = 300005, INF = ~0U >> 2;

struct NODE {
    int u, v, flow, cost;
    int next;
};

int s, t, e;
int head[N], pre[N], visit[N], dis[N];
NODE edge[M];
vi res;

void init(int S, int T) {
    e = 0, s = S, t = T;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int flow, int cost) {
    edge[e].u = u;
    edge[e].v = v;
    edge[e].flow = flow;
    edge[e].cost = cost;
    edge[e].next = head[u];
    head[u] = e++;
    edge[e].u = v;
    edge[e].v = u;
    edge[e].flow = 0;
    edge[e].cost = -cost;
    edge[e].next = head[v];
    head[v] = e++;
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
            if (edge[i].flow > 0 && max(dis[front], edge[i].cost) < dis[k]) {
                dis[k] = max(dis[front], edge[i].cost);
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

struct qnode {
	int v, c;
	qnode(int vv = 0, int cc = 0): v(vv), c(cc) {}
	bool operator <(const qnode& r) const {
		return c > r.c;
	}
};

void dijkstra(int src, int dst, int n) {
	qnode my;
	int i, j, k, now, w;
	priority_queue<qnode> que;
	rep (i, n) visit[i] = 0, dis[i] = INF, pre[i] = -1;
	visit[src] = 1, dis[src] = 0;
	for (now = src, i = 1; i < n; i++) {
		for (j = head[now]; j != -1; j = edge[j].next) {
			k = edge[j].v, w = edge[j].cost;
			if (edge[j].flow == 0) continue;
			if (visit[k] == 0 && max(dis[now], w) < dis[k]) {
				dis[k] = max(dis[now], w);
				que.push(qnode(k, dis[k]));
				pre[k] = j;
				if (k == dst) return ;
			}
		}
		while (!que.empty() && visit[que.top().v] == 1) que.pop();
		if (que.empty()) break;
		visit[now = que.top().v] = 1;
		que.pop();
	}
}

int min_cost() {
    int i, j, ans = 0, mmin;
    while (1) {
        // SPFA();
		dijkstra(s, t, t + 1);
        if (pre[t] == -1) break;
        mmin = INF;
        for (i = t; i != s; i = edge[pre[i]].u)
            if (edge[pre[i]].flow < mmin) mmin = edge[pre[i]].flow;
        for (i = t; i != s; i = edge[pre[i]].u) {
            edge[pre[i]].flow -= mmin;
            edge[pre[i] ^ 1].flow += mmin;
        }
		res.pb(dis[t]);
        ans += dis[t] * mmin;
    }
    return ans;
}



int n, m;
int g[1005][1005];

int main() {
	int u, v, w;
	while (~in2(n, m)) {
		memset(g, 127, sizeof(g));
		rep (i, m) {
			in3(u, v, w);
			g[u][v] = min(g[u][v], w);
		}
		u = 0, v = 2 * n + 1;
		init(u, v);
		FOR (i, 1, n) {
			add_edge(u, i, 1, 0);
			add_edge(i + n, v, 1, 0);
		}
		FOR (i, 1, n) FOR (j, 1, n) {
			if (g[i][j] <= 1000000000) {
				add_edge(i, j + n, 1, g[i][j]);
			}
		}
		res.clear();
		min_cost();
		u = SZ(res);
		rep (i, n - u) res.pb(-1);
		rep (i, n - 1) printf("%d ", res[i]);
		printf("%d\n", res[n - 1]);
	}
	return 0;
}
