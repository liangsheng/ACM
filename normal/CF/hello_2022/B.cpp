#include <bits/stdc++.h>
using namespace std;

int T, n, l, r, c;
map<int, set<int> > q;
map<pair<int, int>, int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        q.clear(), s.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> l >> r >> c;
            q[l].insert(c);
            q[r].insert(c);
            if (s.count(make_pair(l, r))) s[make_pair(l, r)] = min(s[make_pair(l, r)], c);
            else s[make_pair(l, r)] = c;
            int x = q.begin()->first, y = q.rbegin()->first;
            // cout << "x= " << x << " " << y << '\n';
            int a = -1;
            if (s.count(make_pair(x, y))) a = s[make_pair(x, y)];
            int b =  *(q.begin()->second.begin()) + *(q.rbegin()->second.begin());
            if (a != -1 && a < b) b = a;
            cout << b << '\n';
        }
    }
    return 0;
}