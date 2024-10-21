#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

using i64 = long long;
const i64 INF = numeric_limits<i64>::max() / 2;
const int MOD = 998244353;

struct Graph {
    int n, e;                     // n: 点的个数
    vector<int> head, pnt, nxt;   // 用链式前向星存树     
    vector<char> wv;
    vector<vector<int>> dp;

    Graph(int n_) {
        n = n_, e = 0;

        head.assign(n + 1, -1);
        pnt.assign(n * 2, 0);
        nxt.assign(n * 2, 0);
        wv.assign(n * 2, '#');
        dp.assign(2, vector<int>(n + 1, 0));;
    }

    void add_edge(int u, int v, char ch) {
        pnt[e] = v, wv[e] = ch;
        nxt[e] = head[u], head[u] = e++;
    }

    void dfs(int u) {
        dp[0][u] = 1, dp[1][u] = 1;
        char ch = '#';
        i64 tol = 1, c0 = 1, c1 = 1;
        repe (i, u) {
            ch = wv[i];
            dfs(pnt[i]);
            tol = tol * (dp[0][pnt[i]] + dp[1][pnt[i]]) % MOD;
            c0 = c0 * dp[0][pnt[i]] % MOD;
            c1 = c1 * dp[1][pnt[i]] % MOD;
        }
        if (ch == '|') {
            dp[0][u] = c0;
            dp[1][u] = ((tol - c0) % MOD + MOD) % MOD;
        } else if (ch == '&') {
            dp[1][u] = c1;
            dp[0][u] = ((tol - c1) % MOD + MOD) % MOD;
        } else if (ch == '!') {
            dp[0][u] = c1;
            dp[1][u] = c0;
        }
        // cout << "u= " << u << ", dp[0][u]= " << dp[0][u] << ", dp[1][u]= " << dp[1][u] << '\n';
    }

    int solve(int u, int k) {
        dfs(u);
        return dp[k][u];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // freopen("king.in", "r", stdin);
    // freopen("king.out", "w", stdout);

    int n, k, x, y;
    cin >> n >> k;
    Graph G(n);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        char ch = '#';
        if (s == "or") ch = '|';
        else if (s == "and") ch = '&';
        else if (s == "not") ch = '!';
        if (s != "input") {
            cin >> x;
            for (int j = 1; j <= x; j++) {
                cin >> y;
                G.add_edge(i, y, ch);
            }
        }
    }
    cout << G.solve(1, k) << '\n';

    return 0;
}