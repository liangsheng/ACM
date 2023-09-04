#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, p = 1, k;
    stack<int> q;
    vector<int> f(n + 1, 0);
    q.push(1), f[1] = 1;
    cin >> n >> m;
    while (1) {
        cin >> k;
        int p = -1;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            if (a[i] == n) p = n;
            else if (!f[a[i]]) p = a[i];
        }
        if (p == -1) {
            q.pop();
            p = q.top();
            cout << p << '\n';
            cout.flush();
        } else {
            cout << p << '\n';
            cout.flush();
            if (p == n) break;
            q.push(p), f[p] = 1;
        }
    }
    return 0;
}