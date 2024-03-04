#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    freopen("luogu_P1505_1.in", "w", stdout);
    srand(time(0));
    int T = 1;
    while (T--) {
        int n = 200000, m = 200000, maxi = 21;
        cout << n << '\n';

        for (int i = 2; i <= n; i++) {
            int x = rand() % (i - 1) + 1, w = rand() % maxi - maxi / 2;
            cout << x - 1 << ' ' << i - 1 << ' ' << w << '\n';
        }
        
        cout << m << '\n';
        while (m--) {
            int c = rand() % 5;
            int x = rand() % n, y = rand() % n, z = rand() % (n - 1) + 1, w = rand() % maxi - maxi / 2;
            if (c == 0) cout << "SUM " << x << " " << y << '\n';
            else if (c == 1) cout << "MAX " << x << " " << y << '\n';
            else if (c == 2) cout << "MIN " << x << " " << y << '\n';
            else if (c == 3) cout << "N " << x << " " << y << '\n';
            else if (c == 4) cout << "C " << z << " " << w << '\n';
        }
    }

    return 0;
}
