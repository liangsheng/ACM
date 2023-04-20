#include <bits/stdc++.h>
using namespace std;

string s;

bool gao() {
    int n = s.size();
    if (n != 8) return 0;
    if (!(s[0] >= 'A' && s[0] <= 'Z')) return 0;
    if (!(s[n - 1] >= 'A' && s[n - 1] <= 'Z')) return 0;
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        if (!(s[i] >= '0' && s[i] <= '9')) return 0;
        ans = ans * 10 + s[i] - '0';
    }
    return ans >= 100000 && ans <= 999999;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> s) cout << (gao() ? "Yes" : "No") << '\n';
    return 0;
}