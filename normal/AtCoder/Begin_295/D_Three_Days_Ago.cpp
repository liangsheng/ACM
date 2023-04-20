#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s) {
        int n = s.size();
        map<int, int> q;
        int now = 0;
        for (int i = 0; i < n; i++) {
            now ^= 1 << (s[i] - '0');
            q[now]++;
        }
        LL ans = q[0];
        now = 0;
        for (int i = 1; i < n; i++) {
            now ^= 1 << (s[i - 1] - '0');
            q[now]--;
            ans += q[now];
        }
        cout << ans << '\n';
    }
    return 0;
}