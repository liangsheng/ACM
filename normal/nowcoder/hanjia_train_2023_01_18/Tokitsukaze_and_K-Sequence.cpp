#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m, x;
    cin >> T;
    while (T--) {
        cin >> n;
        map<int, int> q;
        for (int i = 0; i < n; i++) {
            cin >> x;
            q[x]++;
        }
        vector<int> a(N + 5, 0), b(N + 5, 0), R(N + 5, 0);
        for (auto it : q) a[it.second]++;
        for (int i = 1; i <= N; i++) b[i] = b[i - 1] + a[i] * i;
        for (int i = N; i >= 1; i--) R[i] = R[i + 1] + a[i];
        for (int k = 1; k <= n; k++) {
            int ans = b[k] + R[k + 1] * (k - 1);
            cout << ans << '\n';
        }
    }
    return 0;
}