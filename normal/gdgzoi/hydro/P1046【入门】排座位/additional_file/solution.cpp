#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    int n, a, b;
    string s;
    while (cin >> n >> a >> b) {
        int ans = 0;
        cin >> s;
        for (int i = 0; i < n; i++) if (s[i] == '.') {
            int j = i;
            while (i + 1 < n && s[i + 1] == '.') i++;
            int d = i - j + 1;
            if (a < b) swap(a, b);
            int c = min(d / 2, b);
            a -= c, b -= c;
            ans += c * 2, d -= 2 * c;
            if (d > 0) {
                c = min(a, (d + 1) / 2);
                a -= c, ans += c;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}