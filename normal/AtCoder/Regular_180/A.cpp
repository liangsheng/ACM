#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = 1;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s[i + 1] == s[i]) continue;
        int j = i;
        while (i + 1 < n && s[i + 1] != s[i]) i++;
        int d = i - j + 1;
        ans = (LL) ans * ((d - 1) / 2 + 1) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
