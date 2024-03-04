#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

/*--------------------- tarjan 有向图强连通分量缩点 begin -------------*/
const int N = 50005, M = N * 4;

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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m, k, q, x, y, u, v;
    while (cin >> n >> m >> k >> q) {
        vector<string> s(n);
        rep (i, n) cin >> s[i];

        auto get_id = [&](int i, int j) {
            return i * m + j;
        };
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        init(n * m);  // 使用 add_edge 前一定要 init()
        rep (i, n) rep (j, m) if (s[i][j] == '.') {
            x = get_id(i, j);
            rep (k, 4) {
                u = i + dx[k], v = j + dy[k];
                if (u < 0 || u >= n || v < 0 || v >= m || s[u][v] == '#') continue;
                add_edge(x, get_id(u, v));
            }
        }
        while (k--) {
            cin >> x >> y >> u >> v;
            add_edge(get_id(x - 1, y - 1), get_id(u - 1, v - 1));
        }

        /*-------------- 调用 tarjan begin ----------------------*/
        rep (i, n * m) if (!dfn[i]) tarjan(i);  // 这里的 n * m 是指点的个数, 本题目相关

        // 缩点, scc 是缩点后点的个数, sccf[i] 是原点 i 缩点之后对应的新点, 从 1 到 scc
        vector<vector<int>> g(scc + 1, vector<int>());
        rep (i, e) {
            int u = frm[i], v = pnt[i];
            u = sccf[u], v = sccf[v];
            if (u != v) g[u].push_back(v);  // 缩点后就是有相边了, 只用添加 1 遍
        }
        /*-------------- 调用 tarjan end ------------------------*/

        function<int(int, int)> dfs = [&](int x, int y) {
            if (x == y) return 1;
            for (int v : g[x]) if (dfs(v, y)) return 1;
            return 0;
        };

        while (q--) {
            cin >> x >> y >> u >> v;
            x = sccf[get_id(x - 1, y - 1)], y = sccf[get_id(u - 1, v - 1)];
            cout << (dfs(x, y) ? 1 : 0) << '\n';
        }
    }
    return 0;
}