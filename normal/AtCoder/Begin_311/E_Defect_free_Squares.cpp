#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, n, x, y;
    while (cin >> h >> w >> n) {
        vector<vector<bool>> f(h + 1, vector<bool>(w + 1, 0));
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            f[x - 1][y - 1] = 1;
        }

        vector<vector<int>> d(h + 1, vector<int>(w + 1, 0));
        for (int i = h - 1; i >= 0; i--) for (int j = w - 1; j >= 0; j--) {
            if (f[i][j]) d[i][j] = 0;
            else d[i][j] = min({d[i + 1][j], d[i][j + 1], d[i + 1][j + 1]}) + 1;
        }

        LL ans = 0;
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
            // cout << "i= " << i << ", j= " << j << " " << R[i][j] << " " << D[i][j] << '\n';
            ans += d[i][j];
        }
        cout << ans << '\n';
    }
    return 0;
}
