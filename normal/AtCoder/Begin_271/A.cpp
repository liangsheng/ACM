#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    while (cin >> n) {
        int p = n / 16, q = n % 16;
        string ans;
        if (p < 10) ans.push_back('0' + p);
        else ans.push_back('A' + p - 10);
        if (q < 10) ans.push_back('0' + q);
        else ans.push_back('A' + q - 10);
        cout << ans << '\n';
    }
    return 0;
}