#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n, 0), b(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = m; i < n; i++) b[i - m] = a[i];
        for (int i = 0; i < n - 1; i++) cout << b[i] << ' ';
        cout << b[n - 1] << '\n';
    }
    return 0;
}