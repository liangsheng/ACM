#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t, a, b;
    while (cin >> n >> m) {
        map<int, set<int>> q;
        for (int i = 0; i < m; i++) {
            cin >> t >> a >> b;
            if (t == 1) q[a].insert(b);
            else if (t == 2) {
                if (q[a].count(b)) q[a].erase(b);
            } else {
                bool f = q[a].count(b) && q[b].count(a);
                cout << (f ? "Yes" : "No") << '\n';
            }
        }
    }
    return 0;
}