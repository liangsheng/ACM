#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    string s;
    while (cin >> h >> w) {
        vector<int> ans(w, 0);
        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < w; j++) ans[j] += s[j] == '#';
        }
        for (int j = 0; j < w - 1; j++) cout << ans[j] << ' ';
        cout << ans[w - 1] << '\n';
    }
    return 0;
}