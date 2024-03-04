#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int d = __gcd(a, b);
        if (d != a) cout << a / d * b << '\n';
        else cout << b / a * b << '\n';
    }
    return 0;
}