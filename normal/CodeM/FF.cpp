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
#include <cfloat>
#define zero(x) (((x)>0?(x):-(x))<eps)

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = edge[i].next)
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
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)

#define sc(x) cout << #x" = " << x << endl
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 1005, M = N * 20 * 4, INF = ~0U >> 2;

struct Edge {
	int u, v, flow, cost;
	int next;

	Edge() {}
	Edge(int A, int B, int C, int D, int E) {
		u = A, v = B;
		flow = C, cost = D, next = E;
	}
};

struct MinCost {

    int num, e;
    int src, dst;
    int tolCost, tolFlow, costOff;
    int head[N];
    bool vis[N];
    Edge edge[M];
    int initFlow[M];
    int d[N];

    void init(int S, int T, int NUM) {
        e = 0;
        src = S, dst = T, num = NUM;
        memset(head, -1, sizeof(head));
    }

	void add_edge(int u, int v, int flow, int cost) {
		edge[e] = Edge(u, v, flow, cost, head[u]);
		initFlow[e] = flow, head[u] = e++;

		edge[e] = Edge(v, u, 0, -cost, head[v]);
		initFlow[e] = 0, head[v] = e++;
	}

    int aug(int u, int flow) {
        if (u == dst) {
            tolCost += costOff * flow;
            tolFlow += flow;
            return flow;
        }

        vis[u] = 1;
        int tmp = flow;

        repe (i, u) {
            if (edge[i].flow && !edge[i].cost && !vis[edge[i].v]) {
                int delta = aug(edge[i].v, tmp < edge[i].flow ? tmp : edge[i].flow);
                edge[i].flow -= delta;
                edge[i ^ 1].flow += delta;
                tmp -= delta;
                if(!tmp) return flow;
            }
        }
        return flow - tmp;
    }

    bool modlabel() {
        int delta = INF;
        rep (u, num) {
            if (!vis[u]) continue;
            repe (i, u) {
                if(edge[i].flow && !vis[edge[i].v] && edge[i].cost < delta) delta = edge[i].cost;
            }
        }
        if(delta == INF) return false;
        rep (u, num) {
            if (!vis[u]) continue;
            repe (i, u) {
                edge[i].cost -= delta;
                edge[i ^ 1].cost += delta;
            }
        }
        costOff += delta;
        return true;
    }

    pii costFlow() {
        tolCost = tolFlow = 0;
        do {
            do {
                memset(vis, 0, sizeof(vis));
            } while (aug(src, INF));
        } while (modlabel());
        return mp(tolCost, tolFlow);
    }

    pii costFlow(vi &realServers) {
        tolCost = tolFlow = 0;
        do {
            do {
                memset(vis, 0, sizeof(vis));
            } while (aug(src, INF));
        } while (modlabel());

		realServers.clear();
		repe (i, src) {
			if (edge[i].flow < initFlow[i]) realServers.pb(edge[i].v);
		}

        return mp(tolCost, tolFlow);
    }

    bool slf_modlabel() {
        rep (i, num) d[i] = INF;
        d[dst] = 0;
        deque<int> Q;
        Q.push_back(dst);
        while (!Q.empty()) {
            int u = Q.front(), tmp;
            Q.pop_front();
            repe (i, u) {
                if(edge[i ^ 1].flow && (tmp = d[u] - edge[i].cost) < d[edge[i].v]) {
                    (d[edge[i].v] = tmp) <= d[Q.empty() ? src : Q.front()] ? Q.push_front(edge[i].v) : Q.push_back(edge[i].v);
                }
            }
        }
        rep (u, num) repe (i, u) {
            edge[i].cost += d[edge[i].v] - d[u];
        }
        costOff += d[src];
        return d[src] < INF;
    }

    pii slf_costFlow(vi &realServers) {
        tolCost = tolFlow = 0;
        while (slf_modlabel()) {
            do {
                memset(vis, 0, sizeof(vis));
            } while(aug(src, INF));
        }

		realServers.clear();
		repe (i, src) {
			if (edge[i].flow < initFlow[i]) realServers.pb(edge[i].v);
		}

        return mp(tolCost, tolFlow);
    }

} G;

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
		G.init(0, 2 * n + 1, 2 * n + 2);
		FOR (i, 1, n) {
			G.add_edge(u, i, 1, 0);
			G.add_edge(i + n, v, 1, 0);
		}
		FOR (i, 1, n) FOR (j, 1, n) {
			if (g[i][j] <= 1000000000) {
				G.add_edge(i, j + n, 1, g[i][j]);
			}
		}
		// res.clear();
		// min_cost();
		// u = SZ(res);
		// rep (i, n - u) res.pb(-1);
		// rep (i, n - 1) printf("%d ", res[i]);
		// printf("%d\n", res[n - 1]);
		pii tmp = G.costFlow();
		cout << tmp.X << ' ' << tmp.Y << '\n';
	}
	return 0;
}
