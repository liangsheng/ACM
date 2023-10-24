#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
    // for (int n = 1; n <= 100; n++) {
        int tol = 0, idx = 0, m = n;
        while (m > 0) {
            tol++;
            if (idx == 0 && m % 3 == 1) idx = tol;
            m = m * 2 / 3;
        }
        cout << tol << ' ' << idx << '\n';

        // vector<int> f(n, 0);
        // for (int i = 0; i < n; i++) f[i] = i + 1;
        // for (int j = 1; j <= n; j++) {
        //     vector<int> g(n + 1, 0);
        //     int y = 0;
        //     for (int i = 0; i < f.size(); i += 3) {
        //         // cout << f[i] << ' ';
        //         if (f[i] == n) idx = j;
        //         g[f[i]] = 1;
        //         y = 1;
        //     }
        //     tol = j - 1;
        //     if (!y) break;
        //     // cout << '\n';
        //     vector<int> a;
        //     for (int i = 0; i < f.size(); i++) if (!g[f[i]]) a.push_back(f[i]);
        //     // cout << f.size() << ' ' << a.size() << ' ' << f.size() * 2 / 3 << '\n';
        //     f = a;
        // }
        // cout << n << " " << tol << ' ' << idx << '\n';
    }
    // while (cin >> n) {
    // // for (int n = 1; n <= 100; n++) {
    //     int tol = 0, idx;
    //     vector<int> f(n, 0);
    //     for (int i = 0; i < n; i++) f[i] = i + 1;
    //     for (int j = 1; j <= n; j++) {
    //         vector<int> g(n + 1, 0);
    //         int y = 0;
    //         for (int i = 0; i < f.size(); i += 3) {
    //             // cout << f[i] << ' ';
    //             if (f[i] == n) idx = j;
    //             g[f[i]] = 1;
    //             y = 1;
    //         }
    //         tol = j - 1;
    //         if (!y) break;
    //         // cout << '\n';
    //         vector<int> a;
    //         for (int i = 0; i < f.size(); i++) if (!g[f[i]]) a.push_back(f[i]);
    //         cout << f.size() << ' ' << a.size() << ' ' << f.size() * 2 / 3 << '\n';
    //         f = a;
    //     }
    //     cout << n << ' ' << tol << ' ' << idx << '\n';
    // }
    return 0;
}