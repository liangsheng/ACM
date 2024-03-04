#include <bits/stdc++.h>
typedef long long LL;  // 表示以后需要写 long long 的地方可以用 LL 代替
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    while (cin >> n) {
        priority_queue<LL> q;
        for (int i = 0; i < n; i++) {
            cin >> x;
            q.push(-x);
        }
        if (n == 1) {
            cout << x << '\n';
            continue;
        }
        LL ans = 0;
        while (!q.empty()) {
            x = q.top(), q.pop();
            y = q.top(), q.pop();
            ans += -x - y;
            if (!q.empty()) q.push(x + y);
        }
        cout << ans << '\n';
    }
    return 0;
}