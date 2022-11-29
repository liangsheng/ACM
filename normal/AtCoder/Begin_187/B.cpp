#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n;
int x[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
            double k = (y[j] - y[i]) * 1.0 / (x[j] - x[i]);
            ans += (k >= -1 && k <= 1);
        }
        cout << ans << '\n';
    }
    return 0;
}