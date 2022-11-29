#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;

int T, n;
int R[N];
string s;

LL gao() {
    int r = 0;
    LL ans = 0;
    n = s.size();
    R[n - 1] = (s[n - 1] == '?' ? n : n - 1);
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] != '?') R[i] = i;
        else R[i] = R[i + 1];
    }
    for (int i = 0; i < n; i++) {
        if (R[i] == n) {
            ans += n - i;
            continue;
        }
        r = max(r, R[i]);
        char id = s[R[i]];
        while (r + 1 < n && (s[r + 1] == '?' || (s[r + 1] == id && (r + 1 - R[i]) % 2 == 0) || (s[r + 1] != id && (r + 1 - R[i]) % 2 == 1))) r++;
        ans += r - i + 1;
        // cout << i << ' ' << R[i] << ' ' << r << ' ' << ans << '\n';
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> s;
        cout << gao() << '\n';
    }
    return 0;
}