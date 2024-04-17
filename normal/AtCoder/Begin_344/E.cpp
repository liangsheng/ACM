#include <bits/stdc++.h>
using namespace std;
 
const int N = 400005;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c, x, y, e = 2;
    cin >> n;
    map<int, int> q;
    vector<int> a(N, -1), L(N, -1), R(N, -1);
    int s = 0, t = 1;
    R[s] = t, L[t] = s;

    auto add = [&](int p, int x) {
        a[++e] = x;
        q[x] = e;
        int q = R[p];
        R[p] = e, L[q] = e;
        L[e] = p, R[e] = q;
    };

    auto del = [&](int p) {
        int pre = L[p], nxt = R[p];
        q.erase(a[p]);
        R[pre] = nxt, L[nxt] = pre;
    };

    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (i == 1) add(s, x);
        else add(q[y], x);
        y = x;
    }

    cin >> m;
    while (m--) {
        cin >> c >> x;
        if (c == 1) {
            cin >> y;
            add(q[x], y);
        } else del(q[x]);
    }
    int p = s;
    while (R[p] != t) {
        p = R[p];
        cout << a[p] << ' ';
    }
    cout << '\n';
    return 0;
}