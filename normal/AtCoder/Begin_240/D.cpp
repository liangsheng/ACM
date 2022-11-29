#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, x;
    while (~scanf("%d", &n)) {
        int now = 0;
        vector<int> ans(n, 0);
        vector<int> c(n);
        stack<pair<int, int> > q;
        for (int i = 0; i < n; i++) scanf("%d", &c[i]);
        for (int i = 0; i < n; i++) {
            x = c[i];
            if (q.empty() || q.top().first != x) {
                q.push(make_pair(x, 1));
                now++;
            } else if (q.top().second + 1 < x) {
                q.push(make_pair(x, q.top().second + 1));
                now++;
            } else {
                while (!q.empty() && q.top().first == x) q.pop(), now--;
            }
            ans[i] = now;
            // cout << "i= " << i << ' ' << ans[i] << ' ' << q.empty() << '\n';
        }
        // puts("Hello");
        for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
    }
    return 0;
}