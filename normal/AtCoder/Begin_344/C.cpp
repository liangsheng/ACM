#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l, q, p;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    cin >> m;
    vector<int> b(m);
    for (int& x : b) cin >> x;
    cin >> l;
    vector<int> c(l);
    for (int& x : c) cin >> x;
    set<int> s;
    for (int& x : a) for (int& y : b) for (int& z : c) s.insert(x + y + z);
    cin >> q;
    while (q--) {
        cin >> p;
        cout << (s.count(p) ? "Yes" : "No") << '\n';
    }
    return 0;
}