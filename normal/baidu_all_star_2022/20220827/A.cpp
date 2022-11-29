#include <bits/stdc++.h> 
using namespace std;

const int N = 105, INF = ~0U >> 2;

int T, n, w;
int f[N];

void init() {
    for (int i = 1; i <= n; i++) f[i] = i;
}

int find(int x) {
    if (f[x] == x) return f[x];
    f[x] = find(f[x]);
    return f[x];
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        vector<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            cin >> w;
            if (i < j) q.push_back({w, {i + 1, j + 1}});
        }
        sort(q.begin(), q.end());
        init();
        vector<pair<int, int>> ans;
        for (int i = 0; i < q.size(); i++) {
            auto [x, y] = q[i].second;
            printf("x= %d, y= %d, w= %d\n", x, y, q[i].first);
            int fx = find(x), fy = find(y);
            if (fx == fy) continue;
            puts("done");
            ans.push_back({x, y});
            f[fx] = fy;
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
    return 0;
}