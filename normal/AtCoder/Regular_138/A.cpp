#include <bits/stdc++.h>
using namespace std;

const int INF = ~0U >> 2;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n), b(k);
        for (int i = 0; i < n; i++) cin >> a[i];
        b[k - 1] = a[k - 1];
        for (int i = k - 2; i >= 0; i--) b[i] = min(a[i], b[i + 1]);
        int ans = INF;
        for (int i = k; i < n; i++) {
            auto it = lower_bound(b.begin(), b.end(), a[i]);
            if (it == b.begin()) continue;
            it--;
            // cout << a[i] << ' ' << *it << '\n';
            int id = it - b.begin();
            // cout << "i= " << i << " id= " << id << '\n';
            ans = min(ans, i - id);   
        }
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}