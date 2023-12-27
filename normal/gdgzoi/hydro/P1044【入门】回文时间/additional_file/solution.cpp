#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> ans(24);
    for (int i = 0; i < 24; i++) {
        int d = i % 10 * 10 + i / 10 % 10;
        if (d >= 60) continue;
        ans[i].push_back(i / 10 % 10 + '0');
        ans[i].push_back(i % 10 + '0');
        ans[i].push_back(':');
        ans[i].push_back(i % 10 + '0');
        ans[i].push_back(i / 10 % 10 + '0');
    }
    string s;
    while (cin >> s) {
        int p = 0;
        for (int i = 0; i < 24; i++) if (ans[i] > s) {
            p = i;
            break;
        }
        cout << ans[p] << '\n';
    }
    return 0;
}