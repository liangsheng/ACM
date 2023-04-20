#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        int c = 0;
        for (int i = 1; i <= n; i++) c += (a[i] > 0);
        vector<int> x(n + 1, 0), y(n + 1, 0);
        for (int i = 1; i <= c; i++) x[i] = i;
        for (int i = c + 1; i <= n; i++) x[i] = x[i - 1] - 1;
        for (int i = 1; i < n; i++) cout << x[i] << ' ';
        cout << x[n] << '\n';

        int d = n - c;
        for (int i = 1; i <= 2 * d; i += 2) y[i] = 1, y[i + 1] = 0;
        for (int i = 2 * d + 1; i <= n; i++) y[i] = y[i - 1] + 1;
        for (int i = 1; i < n; i++) cout << y[i] << ' ';
        cout << y[n] << '\n';
    }
    return 0;
}