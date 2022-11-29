#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    while (cin >> h >> w) {
        vector<string> a(w, ""), b(w, "");
        for (int i = 0; i < h; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) a[j].push_back(s[j]);
        }
        for (int i = 0; i < h; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) b[j].push_back(s[j]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout << (a == b ? "Yes" : "No") << '\n';
    }
    return 0;
}