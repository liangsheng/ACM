#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, sz, ans = 0;
    cin >> n >> m >> k;
    vector<vector<int>> c(m);
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        cin >> sz;
        c[i].resize(sz);
        for (int j = 0; j < sz; j++) cin >> c[i][j];
        cin >> s[i];
    }
    for (int st = 0; st < (1 << n); st++) {
        bool ok = true;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < (int) c[i].size(); j++) cnt += (st >> (c[i][j] - 1) & 1);
            if ((cnt >= k && s[i] == "x") || (cnt < k && s[i] == "o")) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << '\n';
    return 0;
}