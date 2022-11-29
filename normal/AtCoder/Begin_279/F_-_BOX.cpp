#include <bits/stdc++.h>
using namespace std;

const int N = 600005;

int f[N];

void init(int n) {
    for (int i = 1; i <= n; i++) f[i] = i;
}

int find(int x) {
    if (f[x] == x) return f[x];
    f[x] = find(f[x]);
    return f[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        init(n + m);
        vector<int> a(n + m + 1, -1);
        for (int i = 1; i <= n; i++) a[i] = i;
        int cmd, x, y, now = n;
        while (m--) {
            cin >> cmd;
            if (cmd == 2) {
                cin >> x;
                a[++now] = x;
                // for (int i = 1; i <= 7; i++) cout << a[i] << ' ';cout << '\n';
            } else if (cmd == 1) {
                cin >> x >> y;
                f[y] = x;
            } else if (cmd == 3) {
                cin >> x;
                // cout << "x= " << x << ", a[x]= " << a[x] << '\n';
                // for (int i = 1; i <= 7; i++) cout << a[i] << ' ';cout << '\n';
                int fa = find(a[x]);
                cout << fa << '\n';
            }
        }
    }
    return 0;
}
