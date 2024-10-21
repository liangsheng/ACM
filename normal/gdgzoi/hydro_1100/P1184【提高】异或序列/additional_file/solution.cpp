#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int INF = numeric_limits<int>::max() / 2;
const int M = 2048;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // freopen("sequence.in", "r", stdin);
    // freopen("sequence.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    i64 ans = 0;
    vector<int> c(M, 0), d(M, 0), b(M, 0);
    vector<i64> R(M, 0);
    for (int i = n; i >= 2; i--) {
        fill(d.begin(), d.end(), 0);
        d[a[i]]++;
        for (int j = 0; j < M; j++) d[j ^ a[i]] += b[j];
        b = d;
        for (int j = 0; j < M; j++) R[j] += b[j];
    }
    for (int i = 1, t = 0; i < n; i++) {
        fill(d.begin(), d.end(), 0);
        d[a[i]] = 1;
        for (int j = 0; j < M; j++) d[j ^ a[i]] += c[j];
        c = d;

        for (int j = 0; j < M; j++) {
            ans += c[j] * R[j ^ m];
        }

        for (int j = 0; j < M; j++) {
            R[j] -= b[j ^ t];
        }
        b[t ^ a[i + 1]]--;
        t ^= a[i + 1];
    }
    cout << ans << '\n';

    return 0;
}