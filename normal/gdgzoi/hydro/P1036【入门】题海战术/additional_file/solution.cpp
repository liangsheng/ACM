#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, sz, x, c;
    cin >> n >> m;
    // s 存储学生做过的题, fs 存储学生没做过的题
    vector<set<int>> s(n + 1), fs(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> sz;
        for (int j = 1; j <= sz; j++) {
            cin >> x;
            s[i].insert(x);  // 学生 i 做过的题
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!s[i].count(j)) fs[i].insert(j);  // 学生 i 没过过的题
        }
    }
    cin >> k;
    for (int t = 1; t <= k; t++) {
        cin >> c >> sz;
        set<int> g;

        for (int i = 0; i < sz; i++) {
            cin >> x;
            if (c == 0) {
                // 比赛，统计出至少有 1 个人做过的题
                for (int y : s[x]) g.insert(y);
            } else {
                // 训练，统计出至少有 1 个人没做过的题
                for (int y : fs[x]) g.insert(y);
            }
        }
        for (int i = 1; i <= m; i++) {
            if (!g.count(i)) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}