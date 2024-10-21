// https://contest.xinyoudui.com/contest/279/problem/1451
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("confess.in", "r", stdin);
    freopen("confess.out", "w", stdout);

    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.size();
        vector<int> ans(n + 1, 0);
        // p2: +2 的个数, m2: -2 的个数
        int p2 = 0, m2 = 0;
        for (int i = 0; i < n; i++) {
            ans[0] += (s[i] == '+' ? 1 : -1);
            if (s[i] == '-' && i % 2 == 0) p2++;
            else if (s[i] == '+' && i % 2 == 1) m2++;
        }
        for (int i = 1; i <= n; i++) {
            if (i <= p2) ans[i] = ans[i - 1] + 2;
            else if (i <= n - m2) ans[i] = ans[i - 1];
            else ans[i] = ans[i - 1] - 2;
        }
        for (int i = 0; i <= n; i++) cout << ans[i] << " \n"[i == n];
    }
    return 0;
}