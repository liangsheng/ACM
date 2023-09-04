#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x)
using namespace std;
typedef pair<int, int> pii;

int read() {
	int x = 0, y = 1;
	char ch = gc();
	while (ch < 48 || ch > 57){
		if (ch == '-') y = 0;
	 	ch = gc();
	} while (ch > 47 && ch < 58) x = x * 10 + ch - 48, ch = gc();
	return y ? x : -x;
}
void write(int x){
    if (x > 9) write(x / 10);
    pc(x % 10 + 48);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, k, x, y;
    n = read(), m = read(), k = read();
    // while (cin >> n >> m >> k) {
        vector<vector<int>> g(n + 1, vector<int>());
        for (int i = 1; i <= m; i++) {
            // cin >> x >> y;
            x = read(), y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }

        priority_queue<pii> q;
        vector<int> d(n + 1, -1);
        for (int i = 1; i <= k; i++) {
            // cin >> x >> y;
            x = read(), y = read();
            d[x] = y;
            q.push({y, x});
        }
        while (!q.empty()) {
            auto [du, u] = q.top();
            q.pop();
            if (du < d[u]) continue;
            if (d[u] - 1 < 0) continue;
            for (int v : g[u]) if (d[v] < d[u] - 1) {
                d[v] = d[u] - 1;
                q.push({d[v], v});
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) if (d[i] >= 0) ans++;
        // cout << ans.size() << '\n';
        // for (int i = 0; i < (int) ans.size() - 1; i++) cout << ans[i] << ' ';
        // cout << ans[ans.size() - 1] << '\n';
        write(ans), pc('\n');
        for (int i = 1; i <= n; i++) if (d[i] >= 0) write(i), pc(' ');
    // }
    return 0;
}