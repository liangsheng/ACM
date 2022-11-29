#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W, N, h, w, x;
    while (cin >> H >> W >> N >> h >> w) {
        vector<vector<vector<int>>> f(N + 1, vector<vector<int>>(H + 1, vector<int>(W + 1, 0)));
        for (int i = 1; i <= H; i++) for (int j = 1; j <= W; j++) {
            cin >> x;
            f[x][i][j]++;
        }
        for (int k = 1; k <= N; k++) for (int i = 1; i <= H; i++) for (int j = 1; j <= W; j++) {
            f[k][i][j] = f[k][i][j] + f[k][i - 1][j] + f[k][i][j - 1] - f[k][i - 1][j - 1];
        }
        vector<vector<int>> ans(H - h + 2, vector<int>(W - w + 2, 0));
        vector<int> d(N + 1, 0);
        for (int i = 1; i <= N; i++) d[i] = f[i][H][W];//, cout << "i= " << i << ", d= " << d[i] << '\n';
        for (int i = 1; i + h - 1 <= H; i++) for (int j = 1; j + w - 1 <= W; j++) {
            int I = i + h - 1, J = j + w - 1, tmp = 0;
            // cout << "i= " << i << ", j= " << j << '\n';
            for (int k = 1; k <= N; k++) {
                int h = f[k][I][J] - f[k][I][j - 1] - f[k][i - 1][J] + f[k][i - 1][j - 1];
                // cout << "k= " << k << ", h= " << h << '\n';
                if (d[k] - h > 0) tmp++;
            }
            ans[i][j] = tmp;
        }
        for (int i = 1; i <= H - h + 1; i++) {
            for (int j = 1; j <= W - w; j++) cout << ans[i][j] << ' ';
            cout << ans[i][W - w + 1] << '\n';
        }
    }
    return 0;
}