#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

string gao(string s) {
    string t;
    for (int i = 0; i < s.size() - 1; i++) if (s[i] == 'A') t.push_back(s[i + 1]);
    for (int i = 0; i < s.size() - 1; i++) if (s[i] == 'B') t.push_back(s[i + 1]);
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        for (int i = 0; i < n - 1; i++) s = gao(s);
        cout << s << '\n';
    }
    return 0;
}