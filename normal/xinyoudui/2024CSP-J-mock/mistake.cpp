// https://contest.xinyoudui.com/contest/280/problem/1439
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 INF = numeric_limits<i64>::max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("mistake.in", "r", stdin);
    freopen("mistake.out", "w", stdout);

    int n;
    cin >> n;
    vector<i64> a(n + 2), L(n + 2, 0), R(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i]; 
    for (int i = 1; i <= n; i++) L[i] = L[i - 1] ^ a[i];
    for (int i = n; i >= 1; i--) R[i] = R[i + 1] ^ a[i];
    i64 mini = INF, maxi = -INF;
    for (int i = 1; i < n; i++) {
        i64 tmp = (L[i] + a[i + 1]) ^ R[i + 2];
        mini = min(mini, tmp);
        maxi = max(maxi, tmp);
    }
    cout << mini << ' ' << maxi << '\n';
    return 0;
}