#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // freopen("fool.in", "r", stdin);
    // freopen("fool.out", "w", stdout);

    string s;
    cin >> s;
    int n = s.size(), m;
    cin >> m;
    vector<int> p(m - 1);
    for (int i = 0; i < m - 1; i++) cin >> p[i];
    p.push_back(n);
    int ans = 0, l = 0, r, id = 0;
    for (int k = 0; k < m; k++) {
        int ok = 0, r = p[k];
        for (int i = l; i < r; i++) if (s[i] == 'r') {
            ok = 1;
            break;
        }
        ans += ok;
        l = r;
    }
    cout << ans << '\n';

    return 0;
}