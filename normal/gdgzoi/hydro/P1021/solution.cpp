#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int sum = 0, cnt = 0;
        vector<bool> f(n, 0);
        sort(a, a + n);
        for (int i = n - 1; i >= 0; i--) {
            if (sum + a[i] <= n) {
                sum += a[i];
                f[i] = 1, cnt++;
                if (sum == n) break;
            }
        }
        if (sum < n) cout << -1 << '\n';
        else {
            cout << cnt << '\n';
            for (int i = 0; i < n; i++) if (f[i]) {
                cout << a[i] << ' ';
            }
        }
    }
    return 0;
}