#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0, now = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            while (a[i] > now + 1) {
                ans++;
                now += now + 1;
            }
            if (now < m) now += a[i];
        }
        while (now < m) {
            ans++;
            now += now + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}