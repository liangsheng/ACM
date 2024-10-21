#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = ~0U >> 2, M = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<vector<int>> a(n, vector<int>(5, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++) cin >> a[i][j];

        int cnt = 0;
        vector<int> f(M, 0);
        auto ch = [&](vector<int>& c) {
            int ans = 0;
            for (int i = 0; i < 5; i++) ans = ans * 10 + c[i];
            // cout << ans << '\n';
            cnt++;
            return ans;
        };
        
        auto gao = [&](int k) {
            for (int i = 0; i < 5; i++) {
                for (int j = 1; j < 10; j++) {
                    a[k][i] = (a[k][i] + 1) % 10;
                    f[ch(a[k])]++;
                }
                a[k][i] = (a[k][i] + 1) % 10;
            }
            // cout << "cntcnt= " << cnt << '\n';
            for (int i = 0; i < 4; i++) {
                int j = i + 1;
                for (int h = 1; h < 10; h++) {
                    a[k][i] = (a[k][i] + 1) % 10;
                    a[k][j] = (a[k][j] + 1) % 10;
                    f[ch(a[k])]++;
                }
                a[k][i] = (a[k][i] + 1) % 10;
                a[k][j] = (a[k][j] + 1) % 10;
            }
        };
        for (int i = 0; i < n; i++) gao(i);
        // cout << "cnt= " << cnt << '\n';
        int ans = 0;
        for (int i = 0; i < M; i++) if (f[i] == n) ans++;
        cout << ans << '\n';
    }
    return 0;
}