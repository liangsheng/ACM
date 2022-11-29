#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    LL n;
    while (cin >> n) {
        string ans;
        while (n != 0) {
            if (n & 1) ans.push_back('2');
            else ans.push_back('0');
            n >>= 1LL;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    return 0;
}