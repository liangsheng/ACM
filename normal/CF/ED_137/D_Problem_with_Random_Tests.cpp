#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    while (cin >> n) {
        cin >> s;

        vector<int> a;
        for (int i = 0; i < n; i++) if (s[i] == '0') a.push_back(i);
        if (a.size() == 0) {
            cout << s << '\n';
            continue;
        }
        
    }
    return 0;
}