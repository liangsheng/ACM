#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, cas = 0, n;
    string s, ans;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.size();
        ans.clear();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (i + 1 < n && s[i + 1] == s[j]) i++;
            if (i == n - 1 || s[i + 1] < s[j]) {
                for (int k = j; k <= i; k++) ans.push_back(s[j]);
            } else {
                for (int k = j; k <= i; k++) ans.push_back(s[j]), ans.push_back(s[j]);
            }
        }
        cout << "Case #" << ++cas << ": " << ans << '\n';
    }
    return 0;
}