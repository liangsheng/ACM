#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, x;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> c(n);
        map<int, vector<int>> a;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            a[c[i]].push_back(i);
        }
        x = n;
        for (int i = 0; i <= n; i++) if (!a.count(i)) {
            x = i;
            break;
        }
        // cout << "x= " << x << '\n';
        if (x == 0) cout << "Yes" << '\n';
        else if (x == n) cout << "No" << '\n';
        else if (a[x + 1].empty()) cout << "Yes" << '\n';
        else {
            int L = a[x + 1][0], R = *a[x + 1].rbegin();
            for (int i = L; i <= R; i++) c[i] = x;
            set<int> s;
            for (int i = 0; i < n; i++) s.insert(c[i]);//, cout << c[i] << ' ';
            // cout << '\n';
            bool f = 1;
            for (int i = 0; i <= x; i++) if (!s.count(i)) {
                f = 0;
                break;
            }
            cout << (f ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}