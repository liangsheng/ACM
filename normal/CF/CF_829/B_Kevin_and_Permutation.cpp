#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<vector<int>> a(2, vector<int>());
        for (int i = n / 2 + 1; i <= n; i++) a[0].push_back(i);
        for (int i = 1; i < n / 2 + 1; i++) a[1].push_back(i);
        vector<int> ans;
        int now = 0, p[2] = {0, 0};
        for (int i = 0; i < n; i++) {
            ans.push_back(a[now][p[now]++]);
            now ^= 1;
        }
        for (int i = 0; i < n - 1; i++) cout << ans[i] << ' ';
        cout << ans[n - 1] << '\n';
    }
    return 0;
}