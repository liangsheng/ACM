#include <bits/stdc++.h>
using namespace std;

int T, n;
string s;
set<int> a = {2, 3, 5, 7};
set<int> b = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void gao() {
    for (int i = 0; i < n; i++) if (!a.count(s[i] - '0')) {
        cout << 1 << '\n';
        cout << s[i] << '\n';
        return ;
    }
    cout << 2 << '\n';
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        int d = 10 * (s[i] - '0') + s[j] - '0';
        if (!b.count(d)) {
            cout << d << '\n';
            return ;
        }
    }
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