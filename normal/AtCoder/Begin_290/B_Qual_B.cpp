#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'x') continue;
            if (m > 0) m--;
            else s[i] = 'x';
        }
        cout << s << '\n';
    }
    return 0;
}