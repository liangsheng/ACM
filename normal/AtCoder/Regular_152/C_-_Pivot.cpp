#include <bits/stdc++.h>
using namespace std;

const int INF = ~0U >> 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        if (a[0] == 0) {
            cout << a[n - 1] << '\n';
            continue;
        }
        int id = lower_bound(a.begin(), a.end(), (a[n - 1] + 1) / 2) - a.begin();
        if (id == n - 1) {
            cout << a[n - 1] << '\n';
            continue;            
        }
        
        int ans = INF;
        while (1) {
            sort(a.begin(), a.end());
            int now = a[n - 1];
            if (now < ans) ans = now;
            else break;
            ans = min(ans, now);
            int id = lower_bound(a.begin(), a.end(), (a[n - 1] + 1) / 2) - a.begin();
            int tmp = a[id];
            for (int i = 0; i < n; i++) a[i] = 2 * tmp - a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}