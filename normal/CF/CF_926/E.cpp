#include <bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m, p = -1;
    string s, c;
    cin >> n >> m >> s;
    crope t;
    for (int i = 0; i < n; i++) {
        t.push_back(s[i]);
        if (s[i] == 'I') p = i;
    }
    while (m--) {
        cin >> c;
        if (c == "<-") if (p != 0) {
            t.erase(p, 1);
            t.insert(p - 1, 'I');
            p--;
        } 
        if (c == "->") if (p != n - 1) {
            t.erase(p, 1);
            t.insert(p + 1, 'I');
            p++;
        }
        if (c == "backspace") {
            if (p == 0) continue;
            if (t[p - 1] == '(' && p + 1 < n && t[p + 1] == ')') {
                t.erase(p - 1, 3);
                t.insert(p - 1, 'I');
                n -= 2, p--;
            } else {
                t.erase(p - 1, 1);
                n--, p--;
            }
        }   
        if (c == "delete") if (p != n - 1) {
            t.erase(p + 1, 1);
            n--;
        } 
    }
    cout << t << '\n';
    return 0;
}