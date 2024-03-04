#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // 下面 2 是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n, m;
    while (cin >> n >> m) {
        if ((n + 1) * n < m * 2) {
            cout << "It is raining!" << '\n';
            continue;
        }
        vector<int> ans;
        for (int i = min(n, m); i >= 1 && m >= 0; i--) if (i <= m) {
            ans.push_back(i);
            m -= i;
        }
        cout << ans.size() << '\n';
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << ans[i] << " \n"[i == 0];
        } 
    }
    return 0;
}