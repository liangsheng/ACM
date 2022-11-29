#include <bits/stdc++.h>
using namespace std;

int gao(vector<int>& a) {
    int n = a.size(), INF = ~0U >> 2;
    vector<int> dp(n + 1, INF);
    for (int i = 0; i < n; i++) {
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int solve(int t) {
    int ans = t;
    vector<int> a(t);
    for (int i = 0; i < t; i++) a[i] = i + 1;
    do {
//         for (int i = 0; i < t; i++) cout << a[i] << ' ';
        vector<int> b(t);
        for (int i = 0; i < t; i++) b[i] = -a[i];
        int x = gao(a), y = gao(b), z = max(x, y);
        ans = min(ans, z);
//         cout << x << ' ' << y << ' ' << max(x, y) << '\n';
        // if (x <= 3 && y <= 3) {
        //     for (int i = 0; i < t; i++) cout << a[i] << ' ';
        //     cout << '\n';
        // }
    } while (next_permutation(a.begin(), a.end()));
    return ans;
}

int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int ans = ceil(sqrt(n * 1.0));
        vector<int> a;
        for (int i = 1; i <= n; i += ans) for (int j = min(n, i + ans - 1); j >= i; j--) a.push_back(j);
        for (int i = 0; i < n - 1; i++) cout << a[i] << ' ';
        cout << a[n - 1] << '\n';
    }
    return 0;
}