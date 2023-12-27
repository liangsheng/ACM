#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n;
    string s;
    vector<int> a(10);
    while (cin >> n) {
        cin >> s;
        for (int i = 1; i <= 9; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            int id = s[i] - '0';
            if (a[id] > id) {
                s[i] = a[id] + '0';
                while (i + 1 < n && a[s[i + 1] - '0'] >= s[i + 1] - '0') {
                    s[i + 1] = a[s[i + 1] - '0'] + '0';
                    i++;
                }
                break;
            }
        }
        cout << s << '\n';
    }
    return 0;
}