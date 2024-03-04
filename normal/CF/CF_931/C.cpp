#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, m, x, y, z, p1, q1, p2, q2;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        // n = 4, m = 3;
        // p1 = 2, q1 = 2;
        // p2 = 3, q2 = 2;

        auto gao = [&](int c, int d) {
            int ans = abs(c - p1) + abs(d - q1);
            int res = abs(c - p2) + abs(d - q2);
            return min(ans, res);
        };

        cout << "? 1 1" << '\n';
        cout.flush();
        cin >> x;
        // x = gao(1, 1);
        cout << "? " << n << ' ' << m << '\n';
        cout.flush();
        cin >> y;
        // y = gao(n, m);
        cout << "? " << 1 << ' ' << m << '\n';
        cout.flush();
        cin >> z;
        // z = gao(1, m);
        int u, v;
        if ((x + z - m + 1) % 2 == 0) {
            u = (x + z - m + 1) / 2 + 1;
            v = x - (u - 1) + 1;
        } else {
            v = m - (y + z - n + 1) / 2;
            u = 1 + z - (m - v);                
        }
        cout << "! " << u << ' ' << v << '\n';
        cout.flush();
    }
    return 0;
}