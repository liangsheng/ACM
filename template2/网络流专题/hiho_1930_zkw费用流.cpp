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

const int N = 50 * 50 + 5, M = (50 * 50 * 4 + 50 * 50 * 2) * 2 + 5;
const int INF = ~0U >> 2;

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
        tolCost = tolFlow = costOff = 0;
        do {
            do {
                memset(vis, 0, sizeof(vis));
            } while (aug(src, INF));
        } while (modlabel());

        return mp(tolCost, tolFlow);
    }
} G;

const int NN = 1005;

int n, m;
int g[NN][NN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int S, T, tol;
    while (~in2(n, m)) {
        tol = 0;
        rep (i, n) rep (j, m) {
            in(g[i][j]);
            tol += g[i][j];
        }
        tol /= (n * m);
        S = n * m, T = S + 1;
        G.init(S, T, T + 1);
        rep (i, n) rep (j, m) rep (k, 4) {
            int u = i + dx[k], v = j + dy[k];
            if (u < 0 || u == n || v < 0 || v == m) continue;
            G.add_edge(i * m + j, u * m + v, INF, 1);
        }
        rep (i, n) rep (j, m) {
            if (g[i][j] > tol) G.add_edge(S, i * m + j, g[i][j] - tol, 0);
            else G.add_edge(i * m + j, T, tol - g[i][j], 0);
        }
        pii tmp = G.costFlow();
        printf("%d\n", tmp.X);
    }
    return 0;
}
