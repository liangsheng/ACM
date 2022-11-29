#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, cnt = 0;
    map<string, int> q;
    string s;
    for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) {
        if (i == j) continue;
        s.clear();
        s.push_back('a' + i);
        s.push_back('a' + j);
        q[s] = ++cnt;
    }
    cin >> T;
    while (T--) {
        cin >> s;
        cout << q[s] << '\n';
    }
    return 0;
}