#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL n;
    while (cin >> n) {
        n = n + 1;
        if (n == 1) cout << 0 << '\n';
        else if (n % 2 == 0) cout << n / 2 << '\n';
        else cout << n << '\n';
    }
    return 0;
}