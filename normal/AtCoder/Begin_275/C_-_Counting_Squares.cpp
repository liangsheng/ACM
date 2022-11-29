#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 9, ans = 0;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    auto ok = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n && s[x][y] == '#';
    };
    for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) {
        for (int dx = 1; dx < n; dx++) for (int dy = 0; dy < n; dy++) {
            int x0 = x, y0 = y;
            int x1 = x + dx, y1 = y + dy;
            int x2 = x - dy, y2= y + dx;
            int x3 = x + dx - dy, y3 = y + dx + dy;
            ans += ok(x0, y0) && ok(x1, y1) && ok(x2, y2) && ok(x3, y3);
        }
    }
    cout << ans << '\n';
    return 0;
}

// export http_proxy="http://172.28.32.1:10809"; export https_proxy="http://172.28.32.1:10809"; export HTTP_PROXY="http://172.28.32.1:10809"; export HTTPS_PROXY="http://172.28.32.1:10809";