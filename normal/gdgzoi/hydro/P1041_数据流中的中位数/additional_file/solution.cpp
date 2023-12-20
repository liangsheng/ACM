#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    set<pair<int, int>> s1, s2;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        s1.insert({x, i});
        auto it = s1.rbegin();
        s2.insert(*it);
        s1.erase(*it);
        while (s1.size() < s2.size()) {
            auto it = s2.begin();
            s1.insert(*it);
            s2.erase(*it);
        }

        if (i % 2) cout << s1.rbegin()->first;
        else cout << (s1.rbegin()->first + s2.begin()->first) / 2;
        if (i != n) cout << ' ';
        else cout << '\n';
    }
    return 0;
}