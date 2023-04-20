#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    while (cin >> n >> m) {
        set<int> s;
        for (int i = 0; i < n; i++) cin >> x, s.insert(x);

        int f = 1;
        for (int i = 0; i < m; i++) if (!s.count(i)) {
            f = 0;
            cout << i << '\n';
            break;
        } 
        if (f) cout << m << '\n';
    }
    return 0;
}