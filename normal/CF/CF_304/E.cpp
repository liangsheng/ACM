#include <bits/stdc++.h>

#define file_r(x) freopen(x, stdin, "r")
#define file_w(x) freopen(x, stdout, "w")
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh

#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define be begin
#define nb rbegin
#define er erase
#define SZ(c) c.size()

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 205, M = 2005, INF = ~0U >> 2;

int e, s, t, NN;
int head[N], pre[N], cur[N], dis[N], gap[N];
int pnt[M], wv[M], nxt[M];

void add_edge(int u, int v, int w) {
    //sc3(u, v, w);
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

int n, m;
int a[N], b[N], g[N][N], f[N][N];

int main() {
    int u, v, ans, sum, cnt;
    while (~scanf("%d %d", &n, &m)) {
        sum = cnt = 0;
        FOR (i, 1, n) scanf("%d", &a[i]), sum += a[i];
        FOR (i, 1, n) scanf("%d", &b[i]), cnt += b[i];
        init(0, 2 * n + 1, 2 * n + 2);
        memset(g, -1, sizeof(g));
        FOR (i, 1, n) {
            add_edge(i, i + n, INF);
            g[i][i] = (e - 2) ^ 1;
        }
        FOR (i, 1, n) add_edge(s, i, a[i]);
        FOR (i, 1, n) add_edge(n + i, t, b[i]);
       // printf("e= %d\n", e);
        FOR (i, 1, m) {
            scanf("%d %d", &u, &v);
            add_edge(u, v + n, INF);
            g[u][v] = (e - 2) ^ 1;
            //sc3(u, v, g[u][v]);
            add_edge(v, u + n, INF);
            g[v][u] = (e - 2) ^ 1;
        }
        ans = sap();
        //cout << "ans= " << ans <<'\n';
        if ((sum != cnt) || (ans != sum)) {
            puts("NO");
            continue;
        }
        puts("YES");
        FOR (i, 1, n) FOR (j, 1, n) {
            if (g[i][j] == -1) f[i][j] = 0;
            else f[i][j] = wv[g[i][j]];
        }
        FOR (i, 1, n) {
            FOR (j, 1, n - 1) printf("%d ", f[i][j]);
            printf("%d\n", f[i][n]);
        }
        //cout << g[1][2];
    }
    return 0;
}






















