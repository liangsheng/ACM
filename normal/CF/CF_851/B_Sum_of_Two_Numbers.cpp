#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, e;
    cin >> T;
    while (T--) {
        cin >> n;
        e = n;
        if (n % 2 == 0) cout << n / 2 << ' ' << n / 2 << '\n';
        else {
            int d = n / 2;
            if (d % 10 != 9) cout << d << ' ' << d + 1 << '\n';
            else {
                vector<int> a;
                while (n != 0) a.push_back(n % 10), n /= 10;
                reverse(a.begin(), a.end());
                int m = a.size();
                vector<int> x(m, 0), y(m, 0);
                int f = 0;
                for (int i = 0; i < m; i++) {
                    if (a[i] % 2 == 0) x[i] = a[i] / 2, y[i] = a[i] / 2;
                    else {
                        if (f == 0) x[i] = a[i] / 2, y[i] = a[i] / 2 + 1;
                        else x[i] = a[i] / 2 + 1, y[i] = a[i] / 2;
                        f ^= 1;
                    }
                }
                int c = 0;
                for (int i = 0; i < m; i++) c = c * 10 + x[i];
                cout << c << ' ' << e - c << '\n';
            }
        }
    }
    return 0;
}