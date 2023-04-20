#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();
        set<LL> q;
        for (int i = 0; i < n; i++) q.insert(a[i]);
        LL now = a[0];
        for (int k = 0; k < m; k++) {
            now = *q.begin();
            q.erase(q.begin());
            // cout << "k= " << k << " " << now << '\n';
            for (int i = 0; i < n; i++) {
                q.insert(now + a[i]);
            }
        }
        // cout << q.size() << '\n';
        cout << now << '\n';
    }
    return 0;
}