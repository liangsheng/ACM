#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

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
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()

using namespace std;
int chh;

typedef long long LL;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;

const int N = 205, M = 80000, INF = ~0U >> 2;

int e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];
int pnt[M], wv[M], nxt[M];

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w, nxt[e] = head[u], head[u] = e++;
    pnt[e] = u, wv[e] = 0, nxt[e] = head[v], head[v] = e++;
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
        for (int &j = cur[u]; j != -1; j = nxt[j]) {
            v = pnt[j];
            if (wv[j] > 0 && dis[u] == dis[v] + 1) {
                flag = 1;
                if (wv[j] < aug) aug = wv[j];
                pre[v] = u;
                u = v;
                if (u == t) {
                    flow += aug;
                    while (u != s) {
                        u = pre[u];
                        wv[cur[u]] -= aug;
                        wv[cur[u] ^ 1] += aug;
                    }
                    aug = INF;
                }
                break;
            }
        }
        if (flag) continue;
        int mindis = NN;
        for (int j = head[u]; j != -1; j = nxt[j]) {
            v = pnt[j];
            if (wv[j] > 0 && dis[v] < mindis) {
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

void init(int src, int dst, int num) {
    e = 0, s = src, t = dst, NN = num;
    memset(head, -1, sizeof(head));
}

const int N1 = 105;

int n;
int X[N1], Y[N1], Z[N1], F[N1], L[N1];
int g[N1][N1];
int sum;

int sqr(int x) {
    return x * x;
}

bool judge(int mid) {
    int ans;
    init(0, 2 * n + 1, 2 * n + 2);
    FOR (i, 1, n) {
        add_edge(s, 2 * i - 1, F[i]);
        FOR (j, i + 1, n) {
            if (g[i][j] <= mid) {
                add_edge(2 * i, 2 * j - 1, INF);
                add_edge(2 * j, 2 * i - 1, INF);
            }
        }
    }
    add_edge(1, 2, INF), add_edge(2, t, INF);
    FOR (i, 2, n) add_edge(2 * i - 1, 2 * i, L[i]);
    ans = sap();
    if (ans == sum) return 1;
    return 0;
}

int main() {
    int l, r, mid;
    while (~scanf("%d", &n)) {
        sum = 0;
        FOR (i, 1, n) {
            scanf("%d %d %d %d %d", &X[i], &Y[i], &Z[i], &F[i], &L[i]);
            sum += F[i];
        }
        l = 0, r = 0;
        FOR (i, 1, n) {
            g[i][i] = 0.0;
            FOR (j, i + 1, n) {
                g[i][j] = (sqr(X[i] - X[j]) + sqr(Y[i] - Y[j]) + sqr(Z[i] - Z[j]));
                g[j][i] = g[i][j];
                r = max(r, g[i][j]);
            }
        }
        if (!judge(r)) {
            puts("-1");
            continue;
        }
        while (l != r) {
            mid = (l + r) >> 1;
            if (judge(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%.7lf\n", sqrt(l * 1.0));
    }
    return 0;
}
