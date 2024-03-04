#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    freopen("D_1.in", "w", stdout);
    srand(time(0));
    int T = 1;
    while (T--) {
        int n = 100000, m = 10, maxi = 9;
        cout << n << ' ' << m << '\n';
        for (int i = 1; i <= n; i++) {
            int w = rand() % maxi + 1, c = rand() % maxi + 1;
            cout << w << ' ' << c << '\n';
        }
        for (int i = 2; i <= n; i++) {
            int x = rand() % (i - 1) + 1;
            cout << x << ' ' << i << '\n';
        }

        while (m--) {
            int c = rand() % 4;
            int x = rand() % n + 1, y = rand() % n + 1;
            if (c == 0) cout << "QS " << x << " " << y << '\n';
            else if (c == 1) cout << "QM " << x << " " << y << '\n';
            else if (c == 2) cout << "CC " << x << " " << y << '\n';
            else if (c == 3) cout << "CW " << x << " " << y << '\n';
        }
    }

    return 0;
}
