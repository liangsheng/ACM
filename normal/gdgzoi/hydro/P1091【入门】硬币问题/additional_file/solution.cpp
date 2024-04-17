#include <bits/stdc++.h>
using namespace std;

const int N = 350;

vector<int> a = {1, 3, 6, 10, 15};
vector<int> ans(N + 1);

void dfs(int p, int sum, int cnt) {
    if (p == 5) {
        ans[sum] = min(ans[sum], cnt);
        return ;
    }
    for (int i = 0; i <= 10; i++) dfs(p + 1, sum + a[p] * i, cnt + i);
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(ans.begin(), ans.end(), 1000);
    // 暴力计算 150 以内的最优解
    dfs(0, 0, 0);
    // for (int i = 1; i <= 300; i++) {
    //     int res = 0, d = i;
    //     for (int j = 4; j >= 0; j--) {
    //         int c = d / a[j];
    //         res += c, d -= c * a[j];
    //     }
    //     if (res != ans[i]) {
    //         cout << i << ' ' << ans[i] << ' ' << res << '\n';
    //     }
    // }
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;

        auto gao = [&](int d) {
            int res = 0;
            for (int j = 3; j >= 0; j--) {
                int c = d / a[j];
                res += c, d -= c * a[j];
            }
            return res;
        };

        // 150 以内输出暴力的结果
        if (n < 150) cout << ans[n] << '\n';
        else {
            // 贪心 + 暴力
            int d = n / 15;
            int res = d + gao(n - d * 15);
            for (int i = 1; i <= 10; i++) {
                res = min(res, d - i + ans[n - (d - i) * 15]);
            }
            cout << res << '\n';
        } 
    }
    return 0;
}