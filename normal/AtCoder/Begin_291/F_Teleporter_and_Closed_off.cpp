#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = ~0U >> 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s;
    while (cin >> n >> m) {
        vector<vector<int>> g(n + 1, vector<int>());
        vector<vector<int>> h(n + 1, vector<int>());
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 1; j <= m; j++) if (s[j - 1] == '1') {
                g[i + j].push_back(i);
                h[i].push_back(i + j);
            }
        }

        vector<int> L(n + 1, INF);
        L[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int v : g[i]) L[i] = min(L[i], L[v] + 1); 
        }
        vector<int> R(n + 1, INF);
        R[n] = 0;
        for (int i = n - 1; i >= 1; i--) {
            for (int v : h[i]) R[i] = min(R[i], R[v] + 1);
        }

        vector<int> ans;
        for (int k = 2; k <= n - 1; k++) {
            int tmp = INF;
            for (int i = max(1, k - m); i < k; i++) if (L[i] != INF) {
                for (int v : h[i]) if (v > k && R[v] != INF) {
                    tmp = min(tmp, L[i] + 1 + R[v]);
                }
            }
            if (tmp == INF) tmp = -1;
            ans.push_back(tmp);
        }
        for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << ' ';
        cout << ans[ans.size() - 1] << '\n';
    }
    return 0;
}