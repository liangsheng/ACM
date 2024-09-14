#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int n, m, l, r;
    // cin >> n >> m;
    // vector<int> a(n + 1);
    // for (int i = 1; i <= n; i++) cin >> a[i];
    // for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    // while (m--) {
    //     cin >> l >> r;
    //     swap(a[l], a[r]);
    //     for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    // }
    // for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    
    int n, k, x;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[x] = i;
    }
    vector<pair<int, int>> q;
    while (true) {
        // cout << "GOGOGOG" << '\n';
        int l = -1, r;
        for (int d = 1; d < n; d++) {
            for (int i = 1; i + d <= n; i++) {
                if (a[i] - a[i + d] >= k) {
                    l = i, r = i + d;
                    break;
                }
            }
            if (l != -1) break;
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = i + 1; j <= n; j++) {
        //         if (a[i] - a[j] >= k) {
        //             // cout << "i= " << i << ", j= " << j << '\n';
        //             if (l == -1 || j - i < r - l) l = i, r = j; 
        //             break;
        //         }
        //     }
        // }
        if (l == -1) break;
        q.push_back({a[r], a[l]});
        swap(a[l], a[r]);
    }
    cout << q.size() << '\n';
    for (auto [l, r] : q) cout << l << ' ' << r << '\n';
    return 0;
}
