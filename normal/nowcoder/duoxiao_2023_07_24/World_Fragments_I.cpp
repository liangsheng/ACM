#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL gao(string s) {
    LL ans = 0;
    for (int i = 0; i < s.size(); i++) ans = ans * 2 + s[i] - '0';
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string x, y;
    while (cin >> x >> y) {
        LL ans = gao(x), res = gao(y);
        if (ans == 0) {
            if (res == 0) cout << 0 << '\n';
            else cout << -1 << '\n';
        } else cout << abs(res - ans) << '\n';
    }
    return 0;
}