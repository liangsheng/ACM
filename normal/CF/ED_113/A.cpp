#include <bits/stdc++.h>
using namespace std;

int T, n;
string s;

void gao() {
    for (int i = 0; i < s.size() - 1; i++) {
        if ((s[i] == 'a' && s[i + 1] == 'b') || (s[i] == 'b' && s[i + 1] == 'a')) {
            cout << i + 1 << ' ' << i + 2 << '\n';
            return ;
        }
    }
    cout << "-1 -1\n";
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        gao();
    }
    return 0;
}