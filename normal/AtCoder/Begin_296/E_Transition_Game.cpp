#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> cnt(n + 1, 0), a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
        queue<int> q;
        for (int i = 1; i <= n; i++) if (cnt[i] == 0) q.push(i);

        int ans = n;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans--;
            if (--cnt[a[u]] == 0) q.push(a[u]);
        }
        cout << ans << '\n';
    }
    return 0;
}