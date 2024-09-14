#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') a++;
        else b++;
    }
    if (a > b) {
        for (int i = 0; i < n; i++) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
    } else {
        for (int i = 0; i < n; i++) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    }
    cout << s << '\n';
    return 0;
}