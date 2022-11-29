#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string s;
    while (cin >> s) {
        set<string> q;
        string a;
        a += s[0], a += s[1], a += s[2];
        q.insert(a);
        a.clear(), a += s[0], a += s[2], a += s[1];
        q.insert(a);
        a.clear(), a += s[1], a += s[0], a += s[2];
        q.insert(a);
        a.clear(), a += s[1], a += s[2], a += s[0];
        q.insert(a);
        a.clear(), a += s[2], a += s[0], a += s[1];
        q.insert(a);
        a.clear(), a += s[2], a += s[1], a += s[0];
        q.insert(a);
        cout << q.size() << '\n';
    }
    return 0;
}