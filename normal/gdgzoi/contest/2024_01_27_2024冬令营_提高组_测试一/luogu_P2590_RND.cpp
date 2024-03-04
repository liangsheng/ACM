#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    freopen("P2590_1.in", "w", stdout);
    srand(time(0));
    int T = 1;
    while (T--) {
        int n = 8, m = 10, maxi = 9;
        cout << n << '\n';
        for (int i = 2; i <= n; i++) {
            int x = rand() % (i - 1) + 1;
            cout << x << ' ' << i << '\n';
        }
        for (int i = 1; i <= n; i++) cout << rand() % maxi + 1 << ' ';
        cout << '\n';
        cout << m << '\n';
        while (m--) {
            int c = rand() % 3;
            int x = rand() % n + 1, y = rand() % n + 1;
            if (c == 0) cout << "CHANGE " << x << " " << y << '\n';
            else if (c == 1) cout << "QSUM " << x << " " << y << '\n';
            else if (c == 2) cout << "QMAX " << x << " " << y << '\n';
        }
    }

    return 0;
}
