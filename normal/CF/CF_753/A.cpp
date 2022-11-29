#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, id[27];
    string a, b;
    cin >> T;
    while (T--) {
        cin >> a;
        for (int i = 0; i < 26; i++) id[a[i] - 'a'] = i;
        cin >> b;
        int ans = 0;
        for (int i = 1; i < b.size(); i++) ans += abs(id[b[i] - 'a'] - id[b[i - 1] - 'a']);
        cout << ans << '\n';
    }
    return 0;
}