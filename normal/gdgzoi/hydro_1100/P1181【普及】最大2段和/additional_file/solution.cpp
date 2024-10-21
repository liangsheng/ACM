#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // L[i]: 以 a[i] 结尾的最大和
    vector<int> L(n, 0);
    L[0] = a[0];
    for (int i = 1; i < n; i++) L[i] = a[i] + max(0, L[i - 1]);
    
    // R[i]: 以 a[i] 开头的最大和
    vector<int> R(n, 0);
    R[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        R[i] = a[i] + max(0, R[i + 1]);
    }
    
    vector<int> f(n, 0);
    f[n - 1] = R[n - 1];
    for (int i = n - 2; i >= 0; i--) f[i] = max(R[i], f[i + 1]);
    
    int ans = L[0] + f[1];
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, L[i] + f[i + 1]);
    }
    cout << ans << '\n';
    return 0;
}