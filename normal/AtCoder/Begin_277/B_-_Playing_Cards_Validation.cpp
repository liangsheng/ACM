#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, flag = 1;
    string s;
    set<string> h;
    set<char> a = {'H', 'D', 'C', 'S'};
    set<char> b = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (a.count(s[0]) && b.count(s[1])) h.insert(s);
        else flag = 0;
    }
    // cout << flag << '\n' << s.size() << '\n';
    cout << (flag && h.size() == n ? "Yes" : "No") << '\n';
    return 0;
}