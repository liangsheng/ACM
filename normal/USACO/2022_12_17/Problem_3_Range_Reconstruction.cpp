#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) cin >> a[i][j];
        
        vector<int> b(n + 1, 1), L(n + 1, INF), R(n + 1, -INF);
        L[1] = 1, R[1] = 1;
        for (int j = 2; j <= n; j++) {
            int l = -INF, r = INF, x, y;
            vector<int> c, d;
            for (int i = 1; i < j; i++) {
                if (c.empty()) {
                    if (a[i][j] == a[i][j - 1]) {
                        l = max(l, L[i]);
                        r = min(r, R[i]);
                    } else {
                        x = R[i] - a[i][j], y = L[i] + a[i][j];
                        if (x >= l && x <= r) c.push_back(x);
                        if (y >= l && y <= r) c.push_back(y);
                    }
                } else {
                    d.clear();
                    for (int t : c) {
                        int l = min(L[i], t), r = max(R[i], t);
                        if (r - l == a[i][j]) d.push_back(t);
                    }
                    c = d;
                }
            }
            if (!c.empty()) b[j] = c[c.size() - 1];
            else b[j] = r;
            for (int i = 1; i <= j; i++) {
                L[i] = min(L[i], b[j]);
                R[i] = max(R[i], b[j]);
            }


            // vector<int> c, d;
            // if (a[1][j] == a[1][j - 1]) {
            //     for (int t = L[1]; t <= R[1]; t++) c.push_back(t);
            // } else {
            //     c.push_back(R[1] - a[1][j]);
            //     c.push_back(L[1] + a[1][j]);
            // }
            // for (int i = 2; i < j; i++) {
            //     d.clear();
            //     for (int t : c) {
            //         int l = min(L[i], t), r = max(R[i], t);
            //         if (r - l == a[i][j]) d.push_back(t);
            //     }
            //     c = d;
            // }
            // b[j] = c[0];
            // for (int i = 1; i <= j; i++) {
            //     L[i] = min(L[i], b[j]);
            //     R[i] = max(R[i], b[j]);
            // }
        }
        for (int i = 1; i < n; i++) cout << b[i] << ' ';
        cout << b[n] << '\n';
    }
    return 0;
}