#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, cmd, x, y;
    while (cin >> n >> m) {
        map<int, vector<int>> a, b;
        while (m--) {
            cin >> cmd;
            if (cmd == 1) {
                cin >> x >> y;
                a[y].push_back(x);
                b[x].push_back(y);
            } else {
                cin >> x;
                if (cmd == 2) {
                    sort(a[x].begin(), a[x].end());
                    for (int i = 0; i < a[x].size() - 1; i++) cout << a[x][i] << ' ';
                    cout << a[x][a[x].size() - 1] << '\n';
                } else {
                    sort(b[x].begin(), b[x].end());
                    b[x].erase(unique(b[x].begin(), b[x].end()), b[x].end());
                    for (int i = 0; i < b[x].size() - 1; i++) cout << b[x][i] << ' ';
                    cout << b[x][b[x].size() - 1] << '\n';                    
                }
            }
        }
    }
    return 0;
}