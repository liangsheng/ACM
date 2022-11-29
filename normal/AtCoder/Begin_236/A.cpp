#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string s;
    int a, b;
    while (cin >> s >> a >> b) {
        swap(s[a - 1], s[b - 1]);
        cout << s << '\n';
    }
    return 0;
}