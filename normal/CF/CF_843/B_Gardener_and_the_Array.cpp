#include <bits/stdc++.h>
using namespace std;

const int M = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m, x;
    cin >> T;
    while (T--) {
        cin >> n;
        map<int, int> f;
        vector<vector<int>> a(n, vector<int>());
        for (int i = 0; i < n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> x;
                a[i].push_back(x);
                f[x]++;
            }
        }
        bool flag = 0;
        for (int i = 0; i < n; i++) {
            bool t = 1;
            for (int j = 0; j < a[i].size(); j++) if (f[a[i][j]] == 1) {
                t = 0;
                break;
            }
            if (t) {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }
    return 0;
}