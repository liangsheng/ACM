#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // freopen("hotel.in", "r", stdin);
    // freopen("hotel.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    
    if (m >= n * 2) cout << 0 << '\n';
    else cout << 4 * n - 2 * m << '\n';

    return 0;
}