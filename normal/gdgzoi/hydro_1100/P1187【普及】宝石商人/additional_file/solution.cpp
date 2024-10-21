#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // freopen("jewel.in", "r", stdin);
    // freopen("jewel.out", "w", stdout);

    int n;
    cin >> n;
    double x;
    priority_queue<double> q;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(-x);
    }
    for (int k = 1; k < n; k++) {
        double x = -q.top(); q.pop();
        double y = -q.top(); q.pop();
        q.push(-(x + y) / 2);
    }
    cout << fixed << setprecision(5) << -q.top() << '\n';
    return 0;
}