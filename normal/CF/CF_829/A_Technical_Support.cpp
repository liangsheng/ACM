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
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'Q') cnt++;
            else cnt--;
            cnt = max(cnt, 0);
        }
        cout << (cnt > 0 ? "No" : "Yes") << '\n';
    }
    return 0;
}