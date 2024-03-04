#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;

const int N = 100005, M = N * 2;
const LL INF = numeric_limits<LL>::max() / 2;

/*-------------------------- 并查集 begin -----------------*/
vector<int> f;

void init(int n) {
    f = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) f[i] = i;
}

int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}
/*-------------------------- 并查集 end ------------------*/

/*-------------------------- 倍增LCA begin ---------------*/

const int D = 20;

int n, m, e;
int head[N], pnt[M], nxt[M], wv[M];
int dp[N][D], dep[N];
int mx[N][D][2];  // 不同的最大值和次大值

void init() {
    e = 0;
    // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
    fill(head, head + n + 1, -1);

    // 倍增 LCA 初始化
    dp[1][0] = 0, dep[0] = 0;
    fill(dp[0], dp[0] + D, 0);
    memset(mx[0], -1, sizeof(mx[0]));
}

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w;
    nxt[e] = head[u], head[u] = e++;
}

// 在 x, y, a, b 这 4 个数中找到最大的不同的 2 个数放到 x, y
void gao(int& x, int& y, int a, int b) {
    int maxi = max(x, a);
    if (x != maxi && x >= y) y = x;
    if (a != maxi && a >= y) y = a;
    if (b != maxi && b >= y) y = b;
    x = maxi;
}

void dfs(int x, int id) {
    dep[x] = dep[dp[x][0]] + 1;
    for (int i = 1; i < D; i++) dp[x][i] = dp[dp[x][i - 1]][i - 1];

    for (int i = 1; i < D; i++) {
        mx[x][i][0] = mx[x][i - 1][0];
        mx[x][i][1] = mx[x][i - 1][1];
        gao(mx[x][i][0], mx[x][i][1], mx[dp[x][i - 1]][i - 1][0], mx[dp[x][i - 1]][i - 1][1]);
    }
    repe (i, x) {
        int v = pnt[i];
        if (v == dp[x][0]) continue;
        dp[v][0] = x;
        mx[v][0][0] = wv[i], mx[v][0][1] = -1;
        dfs(v, i);
    }
}

int LCA(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = D - 1; i >= 0; i--) {
        if (dep[dp[a][i]] >= dep[b]) a = dp[a][i];
    }
    if (a == b) return a;
    for (int i = D - 1; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) a = dp[a][i], b = dp[b][i];
    }
    return dp[a][0];
}

int gao(int a, int b, int z) {
    if (dep[a] < dep[b]) swap(a, b);
    int x = -1, y = -1;
    // cout << "mx= " << mx[a][0][0] << ' ' << mx[a][0][1] << '\n';
    for (int i = D - 1; i >= 0; i--) {
        if (dep[dp[a][i]] >= dep[b]) gao(x, y, mx[a][i][0], mx[a][i][1]), a = dp[a][i];
    }
    // cout << "a= " << a << ", b= " << b << ", x= " << x << ", y= " << y << '\n';
    if (a == b) return x == z ? y : x;
    for (int i = D - 1; i >= 0; i--) {
        if (dp[a][i] != dp[b][i]) {
            gao(x, y, mx[a][i][0], mx[a][i][1]);
            gao(x, y, mx[b][i][0], mx[b][i][1]);
            // cout << "aaaa= " << a << ", b= " << b << ", x= " << x << ", y= " << y << '\n';
            a = dp[a][i], b = dp[b][i];
        }
    }
    gao(x, y, mx[a][0][0], mx[a][0][1]);
    gao(x, y, mx[b][0][0], mx[b][0][1]);
    return x == z ? y : x;
}

/*-------------------------- 倍增LCA end -----------------*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int x, y, z;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> g(m);
    vector<bool> ok(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        g[i] = {z, {x, y}};
    }

    // 求最小生成树
    LL mini = 0;
    sort(g.begin(), g.end());
    init(n);  // 初始化并查集
    for (int i = 0; i < m; i++) {
        // auto [x, y] = g[i].second;
        // int z = g[i].first;
        int z = g[i].first, x = g[i].second.first, y = g[i].second.second;
        int fx = find(x), fy = find(y);
        if (fx == fy) continue;
        mini += z;
        f[fx] = fy;
        ok[i] = 1;
    }

    init();
    for (int i = 0; i < m; i++) if (ok[i]) {
        // auto [x, y] = g[i].second;
        // int z = g[i].first;
        int z = g[i].first, x = g[i].second.first, y = g[i].second.second;
        add_edge(x, y, z);
        add_edge(y, x, z);
        // cout << "x= " << x << ", y= " << y << ",z =" <<z << '\n';    
    }
    dfs(1, -1);
    // cout << LCA(2, 4) << " " << LCA(4, 5) << '\n';
    LL ans = INF;
    for (int i = 0; i < m; i++) if (!ok[i]) {
        // auto [x, y] = g[i].second;
        // int z = g[i].first;
        int z = g[i].first, x = g[i].second.first, y = g[i].second.second;
        int t = gao(x, y, z);
        // cout << "x= " << x << ", y= " << y << ",z =" << z << ", t= " << t << '\n';
        if (t != -1) ans = min(ans, mini - t + z);     
    }
    cout << ans << '\n';
    return 0; 
}