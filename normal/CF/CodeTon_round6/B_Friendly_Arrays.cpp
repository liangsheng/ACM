#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int D = 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<int> a(n, 0), b(m, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        
        int x = 0, y = 0;
        vector<int> f(D, 0);
        for (int j = D - 1; j >= 0; j--) for (int i = 0; i < m; i++) f[j] |= (b[i] >> j) & 1;
        for (int j = D - 1; j >= 0; j--) {
            int t = 0;
            for (int i = 0; i < n; i++) t ^= (a[i] >> j) & 1;
            if (t == 1 || (f[j] && n % 2 == 1)) y |= (1 << j);
        }
        for (int j = D - 1; j >= 0; j--) {
            int t = 0;
            for (int i = 0; i < n; i++) t ^= (a[i] >> j) & 1;
            if (!(t == 0 || (f[j] && n % 2 == 0))) x |= (1 << j);
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}