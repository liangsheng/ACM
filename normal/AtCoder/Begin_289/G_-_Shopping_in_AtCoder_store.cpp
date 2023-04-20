#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a;
    a.push_back(1), a.push_back(2);
    cout << a.begin()[2] << '\n';
    int n, m;
    while (cin >> n >> m) {
        vector<int> b(n + 1), c(m + 1);
        for (int i = 1; i <= n; i++) cin >> b[i];
        for (int i = 1; i <= m; i++) cin >> c[i];
    }
    return 0;
}