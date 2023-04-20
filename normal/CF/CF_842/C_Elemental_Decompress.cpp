#include <bits/stdc++.h>
using namespace std;

int T, n;
vector<vector<int>> a;
vector<int> x, y;

bool gao() {
    x = vector<int>(n + 1);
    y = vector<int>(n + 1);
    queue<int> c, d;
    for (int i = n; i >= 1; i--) {
        // cout << "i= " << i << '\n';
        if (a[i].size() > 2) return 0;
        if (a[i].size() == 2) {
            x[a[i][0]] = i, c.push(a[i][1]);
            y[a[i][1]] = i, d.push(a[i][0]);
        } else if (a[i].size() == 0) {
            if (c.size() == 0 || d.size() == 0) return 0;
            int p = c.front(); c.pop();
            int q = d.front(); d.pop();
            x[p] = i, y[q] = i;
        } else if (a[i].size() == 1) {
            if (c.size() == 0 && d.size() == 0) {
                x[a[i][0]] = i;
                y[a[i][0]] = i;
            } else if (c.size() != 0) {
                int p = c.front(); c.pop();
                x[p] = i;
                y[a[i][0]] = i;
                c.push(a[i][0]);
            } else {
                int q = d.front(); d.pop();
                y[q] = i;
                x[a[i][0]] = i;
                d.push(a[i][0]);
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        a = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 0; i < n; i++) {
            int d; cin >> d;
            a[d].push_back(i + 1);
        }
        bool ok = gao();
        if (ok) {
            cout << "YES" << '\n';
            for (int i = 1; i <= n - 1; i++) cout << x[i] << ' '; cout << x[n] << '\n';
            for (int i = 1; i <= n - 1; i++) cout << y[i] << ' '; cout << y[n] << '\n';
        } else cout << "NO" << '\n';
    }
    return 0;
}