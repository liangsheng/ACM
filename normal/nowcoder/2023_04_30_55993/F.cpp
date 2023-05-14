#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;    
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);    
}

void gao(vector<int>& a, vector<int>& b, int m, int k) {
    int h = 0, e = 0, p = 0;
    vector<pair<int, int>> q(m, {-1, -1});
    for (int i = 0; i <= m - k; i++) {
        for (; p < i + k; p++) {
            while (h != e && q[e - 1].first <= b[p]) e--;
            q[e++] = {b[p], p};
        }
        a[i] = q[h].first;
//         cout << "i= " << i << '\n';
//         for (int j = h; j < e; j++) cout << q[j].first << ' ' << q[j].second << '\n';
        while (h != e && q[h].second <= i) h++;
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // int n, m, k;
    // while (cin >> n >> m >> k) {
    int n = 5000, m = 5000, k = 1000;
    https://blog.csdn.net/ucliaohh/article/details/122121295
    clock_t start, end;
    {
        vector<vector<int>> g(n, vector<int>(m, 0));
        start = clock();
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            g[i][j] = lcm(i + 1, j + 1);
        }
        end = clock();
        cout << "execute time: " << double (end - start) / CLOCKS_PER_SEC << '\n';

        vector<vector<int>> a(n, vector<int>(m - k + 1, 0));
        for (int i = 0; i < n; i++) {
            gao(a[i], g[i], m, k);
//             for (int j = 0; j <= m - k; j++) cout << a[i][j] << ' ';
//             cout << '\n';
        }
        LL ans = 0;
        for (int j = 0; j <= m - k; j++) {
            int h = 0, e = 0, p = 0;
            vector<pair<int, int>> q(m, {-1, -1});
            for (int i = 0; i <= n - k; i++) {
                for (; p < i + k; p++) {
                    while (h != e && q[e - 1].first <= a[p][j]) e--;
                    q[e++] = {a[p][j], p};
                }
                ans += q[h].first;
                while (h != e && q[h].second <= i) h++;
            } 
        }
        cout << ans << '\n';
    }
    return 0;
}