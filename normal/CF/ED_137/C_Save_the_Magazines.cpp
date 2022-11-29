#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n + 1);
        cin >> s;
        for (int i = 1; i <= n; i++) cin >> a[i];

        int ans = 0, i = 1;
        while (s[i - 1] == '1') ans += a[i++];
        for (; i <= n; i++) {
            if (s[i - 1] == '0') continue;
            int sum = a[i - 1] + a[i], mini = min(a[i - 1], a[i]), j = i;
            while (i + 1 <= n && s[i] == '1') {
                sum += a[i + 1];
                mini = min(mini, a[i + 1]);
                i++;
            }
            // cout << "i= " << i << ' ' << j << " " << sum << ' ' << mini << '\n';
            ans += sum - mini;
        }
        cout << ans << '\n';
    }
    return 0;
}