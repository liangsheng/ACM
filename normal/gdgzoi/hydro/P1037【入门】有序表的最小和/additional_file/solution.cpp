#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> p(n, 0);
    priority_queue<pii> q;
    for (int i = 0; i < n; i++) q.push({-(a[i] + b[0]), i});
    for (int i = 1; i <= n; i++) {
        auto it = q.top();
        q.pop();
        cout << -it.first << '\n';
        int id = it.second;
        if (++p[id] < n) {
            q.push({-(a[id] + b[p[id]]), id});
        }
    }
    return 0;
}