#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL T, n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        cin >> n >> k;
        if (k < n) k = n / k * k;
        if (k < n) k += k;
        cout << k / n + (k % n > 0) << '\n';
    }
    return 0;
}