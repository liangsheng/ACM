#include <bits/stdc++.h>
using namespace std;

int T, n;
string s;
set<char> q = {'A', 'E', 'I', 'O', 'U'};

int gao() {
    int ans = 2 * n;
    for (int k = 0; k < 26; k++) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == k + 'A') continue;
            if (q.count(s[i]) && !q.count(k + 'A')) tmp++;
            else if (!q.count(s[i]) && q.count(k + 'A')) tmp++;
            else tmp += 2;
        }
        ans = min(ans, tmp);
    }
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int cas = 0;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.size();
        int d = gao();
        cout << "Case #" << ++cas << ": " << d << '\n';
    }
    return 0;
}
