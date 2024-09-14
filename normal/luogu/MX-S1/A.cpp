#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    bool ok = true;
    vector<int> b;
    queue<int> q;
    for (int i = 1; i <= n; i++) if (a[i] > 0) {
        int j = i;
        i++;
        while (i <= n && a[i] == 0) i++;
        if (i > n) {
            ok = false;
            break;
        }
        int x = i, y = j;
        if (a[x] < a[y]) swap(x, y);
        for (int j = 1; j <= a[y]; j++) {
            b.push_back(x);
            b.push_back(y);
        }
        for (int j = 1; j <= (a[x] - a[y]) / 2; j++) {
            b.push_back(x);
            b.push_back(x);
        }
        if ((a[x] - a[y]) % 2) {
            q.push(x);
            if (q.size() == 2) {
                b.push_back(q.front()), q.pop();
                b.push_back(q.front()), q.pop();
            }
        } 
    }
    // cout << "ok= " << ok << '\n';
    if (!ok) cout << -1 << '\n';
    else {
        for (int i = 0; i < n; i++) cout << b[i] << " \n"[i == n - 1];
        // set<int> s;
        // for (int i = 0; i < n; i++) {
        //     s.insert(b[i]);
        //     if (i % 2 && s.size() % 2) {
        //         cout << "FUCK" << '\n';
        //         break;
        //     }
        // }
    }
    return 0;
}
