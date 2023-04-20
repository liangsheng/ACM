#include <bits/stdc++.h>
using namespace std;

int n;
string s[2];

bool gao(int k) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (s[k][i] == 'W') return 0;
        if (s[k ^ 1][i] == 'B') k ^= 1;
        // cout << "i= " << i << ", k= " << k << '\n';
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s[0] >> s[1];
        // cout << gao(0) << ' ' << gao(1) << '\n';
        cout << ((gao(0) | gao(1)) ? "YES" : "NO") << '\n';
    }
    return 0;
}