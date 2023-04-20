#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) if (s[i][j] == 'T' && s[i][j + 1] == 'T') {
                s[i][j] = 'P', s[i][j + 1] = 'C';
                j++;
            }
        }
        for (int i = 0; i < n; i++) cout << s[i] << '\n';
    }
    return 0;
}