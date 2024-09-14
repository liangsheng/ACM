#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (m - x >= 0) m -= x, cnt++;
        else m = 0;
    }
    cout << cnt << '\n';
    return 0;
}