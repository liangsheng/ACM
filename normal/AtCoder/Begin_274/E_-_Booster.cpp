#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<double, double> pii;

const int N = 12, M = 5;

double dp[1 << 12][1 << 5][17];

double cal(pii x, pii y) {
    return sqrt((x.X - y.X) * (x.X - y.X) + (x.Y - y.Y) * (x.Y - y.Y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<pii> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
        for (int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
        int A = 1 << n, B = 1 << m;
        for (int i = 0; i < A; i++) for (int j = 0; j < B; j++) for (int k = 0; k < n + m; k++) {
            dp[i][i] = -1;
        }
        for (int i = 0; i < n; i++) dp[1 << i][0][i] = cal({0.0, 0.0}, a[i]);
        for (int i = 0; i < m; i++) dp[0][1 << i][i + n] = cal({0.0, 0.0}, b[i]);
        for (int i = 0; i < A; i++) for (int j = 0; j < B; j++) {
            if (dp[i][j] < 0) continue;
            for (int k = 0; k < n; k++) {
                if ((i >> k) & 1) continue;
                double tmp = cal()
            }
        }
    }
    return 0;
}