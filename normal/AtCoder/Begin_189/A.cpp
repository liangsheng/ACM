#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s) puts(s[0] == s[1] && s[1] == s[2] ? "Won" : "Lost");
    return 0;
}