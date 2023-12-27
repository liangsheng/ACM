#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, c, x, t;
    cin >> n >> q;
    vector<vector<int>> a(n);
    for (int i = 0; i < q; i++) {
        cin >> c >> t;
        if (c == 0) {
            cin >> x;
            a[t].push_back(x);
        } else if (c == 1) {
            int sz = a[t].size();
            if (sz > 0) {
                for (int j = 0; j < sz - 1; j++) cout << a[t][j] << ' ';
                cout << a[t][sz - 1] << '\n';
            } else {
                cout << '\n';
            }
        } else {
            a[t].clear();
        }
    }
    return 0;
}