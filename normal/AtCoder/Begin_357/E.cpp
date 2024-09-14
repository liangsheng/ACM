#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;

/*--------------------- tarjan 有向图强连通分量缩点 begin -------------*/
const int N = 200005, M = N;

int e, ct, scc;
int head[N], frm[M], pnt[M], nxt[M];
int dfn[N], low[N], ins[N], sccf[N];
stack<int> s;

void init(int n) {
    e = 0, ct = 0, scc = 0;
    fill(head, head + n + 1, -1);
    fill(ins, ins + n + 1, 0);
    fill(dfn, dfn + n + 1, 0);
    fill(low, low + n + 1, 0);
}

void add_edge(int u, int v) {
    frm[e] = u, pnt[e] = v;
    nxt[e] = head[u], head[u] = e++;
}

void tarjan(int u) {
    int v;
    low[u] = dfn[u] = ++ct;
    s.push(u), ins[u] = 1;
    repe (i, u) {
        v = pnt[i];
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = low[u] < low[v] ? low[u] : low[v];       
        } else if (ins[v] && dfn[v] < low[u]) low[u] = dfn[v];          
    }
    if (low[u] == dfn[u]) {
        scc++;
        do {
            v = s.top();
            s.pop();
            ins[v] = 0;
            sccf[v] = scc; 
        }  while (u != v);        
    }
}
/*--------------------- tarjan 有向图强连通分量缩点 end ---------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        add_edge(i, x);
    }

    /*-------------- 调用 tarjan begin ----------------------*/
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);  // 这里的 n * m 是指点的个数, 本题目相关
    // 缩点, scc 是缩点后点的个数, sccf[i] 是原点 i 缩点之后对应的新点, 从 1 到 scc
    vector<vector<int>> g(scc + 1, vector<int>());
    vector<int> in(scc + 1, 0);
    rep (i, e) {
        int u = frm[i], v = pnt[i];
        u = sccf[u], v = sccf[v];
        if (u != v) in[u]++, g[v].push_back(u);  // 缩点后就是有相边了, 只用添加 1 遍
    }
    /*-------------- 调用 tarjan end ------------------------*/

    vector<int> sz(scc + 1, 0);
    for (int i = 1; i <= n; i++) sz[sccf[i]]++;
    // for (int i = 1; i <= n; i++) {
    //     cout << "i= " << i << ", sccf[i]= " << sccf[i] << ", sz[i]= " << sz[sccf[i]] << '\n';
    // }
    
    queue<int> q;
    for (int i = 1; i <= scc; i++) if (in[i] == 0) q.push(i);
    vector<int> dp(scc + 1, 0);
    while (!q.empty()) {
        int u = q.front();
        // cout << "u= " << u << ", sz[u]= " << sz[u] << '\n';
        q.pop();
        for (auto v : g[u]) {
            dp[v] += dp[u] + sz[u];
            if (--in[v] == 0) q.push(v);
        }
    }

    // for (int i = 1; i <= scc; i++) {
    //     cout << "i= " << i << ", sz[i]= " << sz[i] << ", dp[i]= " << dp[i] << '\n';
    // }

    LL ans = 0;
    for (int i = 1; i <= scc; i++) {
        ans += (LL) sz[i] * sz[i] + (LL) sz[i] * dp[i];
    }
    cout << ans << '\n';
    return 0;
}