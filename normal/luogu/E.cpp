#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;

const int N = 5005, M = 5005 * 2;
const int INF = numeric_limits<int>::max() / 2;

/*-------------------------- 邻接表存储 begin -------------*/
int n, e;
int head[N], pnt[M], nxt[M], wv[M];

void init() {
    e = 0;
    // 注意搞清楚是 0 到 n - 1, 还是 1 到 n
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w;
    nxt[e] = head[u], head[u] = e++;
}
/*-------------------------- 邻接表存储 end ---------------*/

LL fd[N][N];

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, x, w, y;
    cin >> n >> q;
    init();
    vector<int> f(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        cin >> f[i];
        add_edge(i, f[i], 1);
        add_edge(f[i], i, 1);
    }

    vector<int> d(n + 1, 0);
    function<void(int, int)> dfs = [&](int u, int fa) {
        repe (i, u) if (pnt[i] != fa) {
            d[pnt[i]] = d[u] + 1;
            dfs(pnt[i], u);
        }
    };

    for (int i = 1; i <= n; i++) for (int j = 0; j < n; j++) fd[i][j] = 0;
    vector<LL> ans(n + 1, 0);

    function<LL(int, int)> cal = [&](int u, int fa) {
        LL res = ans[u];
        repe (i, u) if (pnt[i] != fa) {
            cout << "v= " << pnt[i] << ", fa= " << u << '\n';
            // res += cal(pnt[i], u);
        }
        return res;
    };

    while (q--) {
        cin >> x >> w >> y;
        int t = 0;
        while (x != 0) {
            ans[x] = max(ans[x], fd[x][t] += w); 
            t++, x = f[x];
        }
        cout << cal(y, f[y]) << '\n';
    }
    cout << "over" << '\n';
    return 0;
}