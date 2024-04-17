#include <bits/stdc++.h>
#define FOR(i, n, m) for (int i = n; i <= m; i++)
using namespace std;

const int N = 205, INF = numeric_limits<int>::max() / 2;

int n, m, q;
int d[N][N];

/*-------------------- floyd 求任意 2 点之间最短路 O(n^3) begin ---------*/

void floyd() {
    FOR (k, 1, n) FOR (i, 1, n) FOR (j, 1, n) {
        if (i != k && k != j && i != j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    } 
}

/*-------------------- floyd 求任意 2 点之间最短路 O(n^3) end -----------*/

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) d[i][j] = INF;
        d[i][i] = 0;
    }
    
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);  // 注意: 可能有自环和重边
    }
    
    floyd();
    
    // bool has_neg_circle = false;
    // for (int i = 1; i <= n; i++) if (d[i][i] < 0) {
    //     has_neg_circle = true;  // d[i][i] < 0 说明有负环
    //     break;
    // } 
    
    while (q--) {
        cin >> u >> v;
        if (d[u][v] > 2000000) cout << "impossible" << '\n';
        else cout << d[u][v] << '\n';
    }
    return 0;
}