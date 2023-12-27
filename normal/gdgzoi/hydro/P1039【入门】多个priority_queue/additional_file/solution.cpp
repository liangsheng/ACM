#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, c, x, t;
    cin >> n >> q;
    vector<priority_queue<int>> a(n);
    for (int i = 0; i < q; i++) {
        cin >> c >> t;
        if (c == 0) {
            cin >> x;
            a[t].push(x);
        } else if (c == 1) {
            if (!a[t].empty()) cout << a[t].top() << '\n';
        } else {
            if (!a[t].empty()) a[t].pop();
        }
    }
    return 0;
}